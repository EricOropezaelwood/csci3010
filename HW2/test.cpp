#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Store.h"
#include "Item.h"
#include "TextUI.h"

ShoppingCart sc;
Store store("store.txt");
Item apple(111, "apple", 1.25, 1);
Item banana(112, "banana", .85, 1);
Item coffee(113, "coffee", 2.45, 3);

TEST_CASE ( "addItem", "[shoppingCart]")
{

	SECTION( "addItem" )
	{
		std::vector<Item *> before = sc.get_items();
		//Item banana(112, "banana", .85, 1);
		sc.AddItem(&banana);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(before != after);
	}

}

TEST_CASE ( "removeItem", "[shoppingCart]")
{
	SECTION( "removeItem" )
	{
		sc.AddItem(&apple);
		sc.AddItem(&banana);
		std::vector<Item *> before = sc.get_items();
		sc.RemoveItem(&apple);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(before.size() != after.size());
	}

}

TEST_CASE ( "displayCart", "[shoppingCart]")
{
	SECTION( "displayCart" )
	{
		sc.ClearCart();
		REQUIRE(sc.DisplayCart() == "");
	}

}

TEST_CASE ( "clearCart", "[shoppingCart]")
{
	SECTION( "clearCart" )
	{
		sc.ClearCart();
		std::vector<Item * > empty = sc.get_items();

		REQUIRE(empty.size() == 0);
	}

}

// get item??

TEST_CASE ( "displayInventory", "[store]")
{
	SECTION( "displayInventory" )
	{
		std::string inv = store.DisplayInventory();
		//std::cout << inv << std::endl;
		//std::string expected = "Tea: 2.00 - 7 \nTall Candle: 7.00 - 3 \nKettle: 15.00 - 2 \n";
		//std::cout << expected << std::endl;
		REQUIRE( inv != "");
	}
}

TEST_CASE ( "items", "[store]")
{
	SECTION( "items" )
	{
		std::map<int, std::string> testItems = store.Items();
		REQUIRE( testItems.empty() == false );
	}
}

TEST_CASE ( "cartItems", "[store]")
{
	SECTION( "cartItems" )
	{
		store.AddItemToCart(2);
		std::map<int, std::string> testCartItems = store.CartItems();
		REQUIRE( testCartItems.empty() == false );
	}
}

TEST_CASE ( "addItemToCart", "[store]")
{
	SECTION( "addItemToCart" )
	{
		std::string before = store.DisplayCart();

		store.AddItemToCart(1);
		std::string after = store.DisplayCart();

		REQUIRE( before != after );
	}
}

TEST_CASE ( "removeItemFromCart", "[store]")
{
	SECTION( "removeItemFromCart" )
	{
		std::string before = store.DisplayCart();

		store.RemoveItemFromCart(1);
		std::string after = store.DisplayCart();

		REQUIRE( before != after );
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

	SECTION( "checkout" )
	{
		double final = store.Checkout();

		REQUIRE(final == 0.00 );
	}
}

TEST_CASE ( "clearCartStore", "[store]")
{
	SECTION( "clearCartStore" )
	{
		store.ClearCart();
		std::map<int, std::string> empty = store.CartItems();

		REQUIRE(empty.size() == 0);
	}

}