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
	SECTION( "Basic functionality" )
	{
		std::map<int, std::string> items = store.Items();
		REQUIRE(!store.Items().empty());
	}
	SECTION( "Check if items are correct" )
	{
		std::map<int, std::string> items;
		for (Item * i : inventory) {
			if (i->get_quantity() > 0) {
				items.insert({i->get_id(), i->ToString()});
			}
		}
		REQUIRE(store.Items() == items);
	}	
}

TEST_CASE ( "cartItems", "[store]")
{
	SECTION( "Basic functionality" )
	{
		store.ClearCart();
		REQUIRE(store.CartItems().empty());
	}
	SECTION( "Basic functionality" )
	{
		store.AddItemToCart(2);
		std::map<int, std::string> testCartItems = store.CartItems();
		REQUIRE( testCartItems.empty() == false );
	}
	SECTION( "Check if CartItems are correct" )
	{
		store.AddItemToCart(2);
		std::map<int, std::string> items;
		for (Item * i : sc.get_items()) {
			if (i->get_quantity() > 0) {
				items.insert({i->get_id(), i->ToString()});
			}
		}
		REQUIRE(store.CartItems() == items);
	}
}

TEST_CASE ( "addItemToCart", "[store]")
{
	SECTION( "Basic functionality" )
	{
		std::string before = store.DisplayCart();

		store.AddItemToCart(1);
		std::string after = store.DisplayCart();

		REQUIRE( before != after );
	}
	SECTION( "Check if the item added is the item at the back of vector" )
	{
		store.AddItemToCart(1);
		ShoppingCart * ShoppingCart = store.GetCart();
		std::vector<Item *> items = ShoppingCart->get_items();
		REQUIRE( items.back()->get_id() == 1 );
	}
}

TEST_CASE ( "removeItemFromCart", "[store]")
{
	SECTION( "Check if the item removed is the item at the back of vector" )
	{
		ShoppingCart * ShoppingCart = store.GetCart();
		ShoppingCart->ClearCart();
		store.AddItemToCart(1);
		std::vector<Item *> before = ShoppingCart->get_items();
		store.RemoveItemFromCart(1);
		std::vector<Item *> after = ShoppingCart->get_items();
		before.pop_back();
		REQUIRE( before == after );
	}
}

TEST_CASE ( "displayCartStore", "[store]")
{

	SECTION( "Basic functionality without items" )
	{
		store.ClearCart();
		REQUIRE(store.DisplayCart() == "");
	}
	SECTION( "Basic functionality with items" )
	{
		store.ClearCart();
		store.AddItemToCart(1);
		std::string str = "";
		ShoppingCart * ShoppingCart = store.GetCart();
		std::vector<Item *> items = ShoppingCart->get_items();
		for (Item * i : items) {
			str += i->ToString() + "\n";
		}
		REQUIRE(store.DisplayCart() == str);
	}
}

TEST_CASE ( "checkout", "[store]")
{

	SECTION( "checkout" )
	{
		store.ClearCart();
		double final = store.Checkout();
		REQUIRE(final == 0.00 );
	}
	SECTION( "checkout" )
	{
		store.ClearCart();
		store.AddItemToCart(1);
		ShoppingCart * ShoppingCart = store.GetCart();
		double final = store.Checkout();
		double cost = 0;
		std::vector<Item *> items = ShoppingCart->get_items();
		for (Item * i : items) {
		cost += (i->get_cost() * i->get_quantity()) * 1.08845;
		}
		REQUIRE(final == cost);
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

