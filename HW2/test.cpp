#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <sstream>
#include <fstream>
#include "catch.hpp"
#include "Store.h"
#include "Item.h"
#include "TextUI.h"

ShoppingCart sc;
Store store("store.txt");
std::vector<Item *> inventory = store.GetInventory();

TEST_CASE ( "addItem", "[shoppingCart]")
{

	SECTION( "Basic functionality" )
	{
		std::vector<Item *> before = sc.get_items();
		sc.AddItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();

		REQUIRE(before.size() == after.size() - 1);
	}
	SECTION( "Check if the last item is the one added" )
	{
		std::vector<Item *> before = sc.get_items();
		sc.AddItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();
		REQUIRE(after.back() == inventory[0]);
	}
	SECTION( "Check if inventory's quantity is increased" )
	{
		int before = inventory[0] -> get_quantity();
		sc.AddItem(inventory[0]);
		int after = inventory[0] -> get_quantity();
		REQUIRE(before == after - 1);
	}
}

TEST_CASE ( "removeItem", "[shoppingCart]")
{
	SECTION( "Basic functionality" )
	{
		sc.AddItem(inventory[0]);
		sc.AddItem(inventory[1]);
		std::vector<Item *> before = sc.get_items();
		sc.RemoveItem(inventory[0]);
		std::vector<Item *> after = sc.get_items();
		REQUIRE(before == after);
	}
	SECTION( "Check if inventory's quantity is decreased" )
        {
		sc.AddItem(inventory[0]);
                int before = inventory[0] -> get_quantity();
                sc.RemoveItem(inventory[0]);
                int after = inventory[0] -> get_quantity();
                REQUIRE(before == after + 1);
        }
}

TEST_CASE ( "displayCart", "[shoppingCart]")
{
	SECTION( "Basic functionality with no items in cart" )
	{
		sc.ClearCart();
		REQUIRE(sc.DisplayCart() == "");
	}
	SECTION( "Basic functionality with items in cart" )
	{
		sc.AddItem(inventory[2]);
		sc.AddItem(inventory[1]);
		std::vector<Item *> items = sc.get_items();
		std::string str = "";
		for(Item * i: items){
			str += i->ToString() + "\n";
		}
		REQUIRE(sc.DisplayCart() == str);
	}

}

TEST_CASE ( "clearCart", "[shoppingCart]")
{
	SECTION( "Basic funtionality" )
	{
		sc.ClearCart();
		std::vector<Item * > empty = sc.get_items();

		REQUIRE(empty.size() == 0);
	}

}

/*
No need for getter function!!!
TEST_CASE ( "get_items", "[shoppingCart]")
{
	SECTION( "Basic functionality" )
	{
	}
}
*/

TEST_CASE ( "constructor", "[store]")
{
	SECTION( "Check if inventory is empty" )
	{
		REQUIRE(!inventory.empty());
	}
}

TEST_CASE ( "displayInventory", "[store]")
{
	SECTION( "Basic functionality" )
	{
		std::string str = "";
		for (Item * i : inventory) {
			str += i->ToString() + "\n";
		}
		REQUIRE(store.DisplayInventory() == str);
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

TEST_CASE ( "operator<<", "[item]")
{
	SECTION( "operator<<" )
	{
		Item * i = inventory[0];
		std::ostringstream oss;
		std::streambuf * backup = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());
		std::cout << *i;
		std::cout.rdbuf(backup);
		REQUIRE(oss.str() == i->ToString());
	}
}

