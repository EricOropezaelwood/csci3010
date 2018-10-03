#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Store.h"
#include "Item.h"
#include "TextUI.h"

ShoppingCart sc;
Store store("store.txt");

std::vector<Item *> inventory = store.get_inventory();


TEST_CASE ( "addItem", "[shoppingCart]")
{

	SECTION( "functionality" )
	{
		std::vector<Item *> before = sc.get_items();
		//Item banana(112, "banana", .85, 1);
		sc.AddItem(inventory[1]);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(before != after);
	}

	SECTION( "correctItemAdded" )
	{
		sc.AddItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(after.back() == inventory[0]);
	}

	SECTION( "item added to cart subtracted from inventory")
	{
		int before = inventory[0]->get_quantity();
		sc.AddItem(inventory[0]);
		int after = inventory[0]->get_quantity();
		REQUIRE(before+1 == after);
	}
}

TEST_CASE ( "removeItem", "[shoppingCart]")
{
	SECTION( "functionality" )
	{
		sc.AddItem(inventory[0]);
		std::vector<Item *> before = sc.get_items();
		sc.RemoveItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(before == after);
	}


	SECTION( "correctItemRemoved" )
	{
		sc.AddItem(inventory[0]);
		sc.RemoveItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(after.back() == inventory[0]);
	}

	SECTION( "item removed from cart added to inventory" )
	{
		int before = inventory[0]->get_quantity();
		sc.RemoveItem(inventory[0]);
		int after = inventory[0]->get_quantity();
		REQUIRE(before == after+1);
	}
}

TEST_CASE ( "displayCart", "[shoppingCart]")
{

	SECTION( "empty cart" )
	{
		sc.ClearCart();
		REQUIRE(sc.DisplayCart() == "");
	}

	SECTION( "1 item added, display correctly" )
	{
		sc.AddItem(inventory[0]);
		std::string oneItem = sc.DisplayCart();

		std::vector<Item *> cart_other = sc.get_items();
		std::string invT = "";
	    for (Item * i : cart_other) {
	      invT.append(i->ToString());
	      invT.append("\n");
	    }

		REQUIRE(oneItem == invT);
	}
}


TEST_CASE ( "clearCart", "[shoppingCart]")
{
	SECTION( "functionality" )
	{
		sc.ClearCart();
		std::vector<Item * > empty = sc.get_items();

		REQUIRE(empty.size() == 0);
	}

}


TEST_CASE ( "store", "[store]")
{
	SECTION( "correct read in" )
	{
		Store store2("store.txt");
		std::vector<Item *> inventory2 = store2.get_inventory();
		REQUIRE(inventory2[0]->get_type() != "");
	}
}

TEST_CASE ( "displayInventory", "[store]")
{
	SECTION( "functionality" )
	{
		//std::cout << store.DisplayInventory() << std::endl;
		std::string inv = store.DisplayInventory();
		std::string inv2 = "";
		for (Item * i : inventory) {
    		inv2.append(i->ToString());
    		inv2.append("\n");
  			}
		REQUIRE( inv == inv2);
	}
}

TEST_CASE ( "items", "[store]")
{
	store.AddItemToCart(inventory[0]->get_id());
	SECTION( "check that items are properly added" )
	{
		std::map<int, std::string> testItems = store.Items();
		REQUIRE( testItems.empty() == false );
	}
}

TEST_CASE ( "cartItems", "[store]")
{
	store.AddItemToCart(inventory[1]->get_id());
	SECTION( "functionality/not empty" )
	{
		std::map<int, std::string> testCartItems = store.CartItems();
		REQUIRE( testCartItems.empty() == false );
	}
}

TEST_CASE ( "addItemToCart", "[store]")
{
	SECTION( "functionality" )
	{
		std::string before = store.DisplayCart();

		store.AddItemToCart(inventory[1]->get_id());
		std::string after = store.DisplayCart();

		REQUIRE( before != after );
	}

	SECTION( "reduced inventory" )
	{
		int before = inventory[1]->get_quantity();
		store.AddItemToCart(inventory[1]->get_id());
		int after = inventory[1]->get_quantity();

		REQUIRE( before != after);
	}

}

TEST_CASE ( "removeItemFromCart", "[store]")
{
	SECTION( "functionality" )
	{
		std::string before = store.DisplayCart();

		store.RemoveItemFromCart(inventory[1]->get_id());
		std::string after = store.DisplayCart();

		REQUIRE( before != after );
	}

	SECTION( "increased inventory" )
	{
		int before = inventory[1]->get_quantity();
		store.RemoveItemFromCart(inventory[1]->get_id());
		int after = inventory[1]->get_quantity();

		REQUIRE( before != after);
	}
}

TEST_CASE ( "displayCartStore", "[store]")
{

	SECTION( "displayCartStore" )
	{
		store.ClearCart();
		REQUIRE(store.DisplayCart() == "");
	}

}

TEST_CASE ( "checkout", "[store]")
{
	int beforeOutput = inventory[1]->get_quantity();

	SECTION( "empty total" )
	{
		double final = store.Checkout();

		REQUIRE(final == 0.00 );
	}
	SECTION( "empty cart" )
	{
		std::string testString = store.DisplayCart();
		REQUIRE(testString == "" );
	}
	SECTION( "output value test" )
	{
		// make sure inventory is properly updated after checkout
		int output = inventory[1]->get_quantity();
		REQUIRE(output == beforeOutput);
	}
}

TEST_CASE ( "clearCartStore", "[store]")
{
	SECTION( "functionality" )
	{
		store.ClearCart();
		std::map<int, std::string> empty = store.CartItems();

		REQUIRE(empty.size() == 0 );
	}
	SECTION( "updates cart correctly" )
	{
		store.AddItemToCart(inventory[1]->get_id());
		std::map<int, std::string> notEmpty = store.CartItems();
		store.ClearCart();
		std::map<int, std::string> empty = store.CartItems();

		REQUIRE( notEmpty != empty );
	}
}

TEST_CASE ( "toString", "[item]")
{
	SECTION( "functionality" )
	{
		sc.AddItem(inventory[0]);


		std::vector<Item *> cart_other = sc.get_items();
		std::string invT = "";
	    for (Item * i : cart_other) {
	      invT.append(i->ToString());
	      invT.append("\n");
	    }

		std::string oneItem = sc.DisplayCart();

		REQUIRE( invT == oneItem );

	}
}