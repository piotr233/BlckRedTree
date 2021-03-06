﻿#include <iostream>
#include <assert.h> // na potrzeby testow
#include "pixel_24bit.h"
#include "FreaquencyCounter.h"


// --------------tests--------------

namespace tree_test {


	void search();
	void end();
	void next();
	void append_or_replace();
	void acces_or_asign();
	void copy_constructor();
	void copy_operator();
	void in_order();
	void no_parameter_constructor();
	void iterator();
	void size();

	void run_all() {

		std::clog << " ------- tree_test-------  \n";
		search();
		end();
		next();
		append_or_replace();
		in_order();
		acces_or_asign();
		copy_constructor();
		copy_operator();
		no_parameter_constructor();
		iterator();
	}
	void size() {
		std::clog << "size :\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		assert(t.size() == 7);
		std::clog << " [ ok ]\n";
	}
	void search() {
		std::clog << "search :\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		assert(t.search(1) == 1);
		assert(t.search(100) == 100);

		assert(t.search(6) == 6);
		std::clog << " [ ok ]\n";

	}
	void end() {
		std::clog << "end :\t\t\t";

		tree<int> t(6);

		assert(t.give_root()->end()->get_value() == 6);
		t.append(4);
		assert(t.give_root()->end()->get_value() == 4);
		t.append(7);
		assert(t.give_root()->end()->get_value() == 7);
		t.append(8);
		assert(t.give_root()->end()->get_value() == 8);
		t.append(10);
		assert(t.give_root()->end()->get_value() == 10);
		t.append(9);
		assert(t.give_root()->end()->get_value() == 9);
		t.append(11);
		assert(t.give_root()->end()->get_value() == 11);

		std::clog << " [ ok ]\n";

	}
	void next() {
		std::clog << "next :\t\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		assert(t.give_root()->next(t.give_root()->get_value())
			->get_value() == 2
		);
		int temp_debug = t.give_root()->search(4)->next(t.give_root()->search(4)->get_value())->get_value();
		assert(temp_debug == 5);

		auto fifth = t.give_root()->search(5);
		temp_debug = fifth->next(fifth->get_value())->get_value();

		assert(temp_debug == 100);
		std::clog << " [ ok ]\n";


	}
	void in_order() {
		std::clog << "in_order :\t\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		unsigned counter = 3;
		assert(t.give_root()->in_order(counter)->get_value() == 4);

		counter = 2;
		assert(t.give_root()->in_order(counter)->get_value() == 1);

		counter = 6;
		assert(t.give_root()->in_order(counter)->get_value() == 10);

		counter = 7;
		assert(t.give_root()->in_order(counter)->get_value() == 11);
		counter = 8;
		assert(t.give_root()->in_order(counter) == nullptr);

		std::clog << " [ ok ]\n";


	}
	void append_or_replace() {

		std::clog << "append_or_replace :\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);

		assert(t.give_root()->search(1)->get_value() == 1);

		assert(t.give_root()->search(100)->get_value() == 100);
		t.give_root()->append_or_replace(100);
		assert(t.give_root()->search(100)->get_value() == 100);
		assert(t.give_root()->search(0) == nullptr);

		std::clog << " [ ok ]\n";


	}
	void acces_or_asign() {

		std::clog << "acces_or_asign :\t";

		{
			using pair = my::pair<int, char>;
			tree<pair> t;

			t.append(pair(2, 'a'));
			t.append(pair(1, 'b'));
			t.append(pair(4, 'c'));
			t.append(pair(4, 'd'));
			t.append(pair(100, 'c'));
			t.append(pair(10, 'e'));
			t.append(pair(5, 'f'));

			pair search(1, 'n');

			pair temp_debug = t[search];
			assert(temp_debug.second == 'b');

			search.first = 100;
			search.second = 'n';

			assert(t[search].second == 'c');

			t.give_root()->append_or_replace((pair(100, 'y')));

			assert(t[search].second == 'y');
			search.first = 0;
			search.second = 's';

			assert(t[search].second == 's');
			search.first = 6;
			search.second = 'f';

			assert(t[search].second == 'f');
		}
		using pair = my::pair<int, std::string>;
		tree<pair> t;

		t.append(pair(2, "a"));
		t.append(pair(1, "b"));
		t.append(pair(4, "c"));
		t.append(pair(4, "d"));
		t.append(pair(100, "c"));
		t.append(pair(10, "e"));
		t.append(pair(5, "f"));

		pair search(1, "n");

		pair temp_debug = t[search];
		assert(temp_debug.second == "b");

		search.first = 100;
		search.second = "n";

		assert(t[search].second == "c");

		t.give_root()->append_or_replace((pair(100, "y")));

		assert(t[search].second == "y");
		search.first = 0;
		search.second = "s";

		assert(t[search].second == "s");
		search.first = 6;
		search.second = "f";

		assert(t[search].second == "f");



		std::clog << " [ ok ]\n";


	}
	void no_parameter_constructor() {
		std::clog << "no_param_constructor :\t";

		tree<int> t;
		t.append(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		unsigned counter = 3;
		assert(t.give_root()->in_order(counter)->get_value() == 4);


		counter = 2;
		assert(t.give_root()->in_order(counter)->get_value() == 1);

		counter = 6;
		assert(t.give_root()->in_order(counter)->get_value() == 10);
		counter = 7;
		assert(t.give_root()->in_order(counter)->get_value() == 11);

		counter = 8;
		assert(t.give_root()->in_order(counter) == nullptr);


		std::clog << " [ ok ]\n";




	}
	void copy_constructor() {
		std::clog << "copy_constructor :\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g(t);

		assert(t[1] == 1);
		assert(t[100] == 100);
		t.give_root()->append_or_replace(100);
		assert(t[100] == 100);
		assert(t[0] == 0);
		assert(t[6] == 6);
		std::clog << " [ ok ]\n";

	}
	void copy_operator() {
		std::clog << "copy_operator :\t\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g = t;

		assert(t[1] == 1);
		assert(t[100] == 100);
		t.give_root()->append_or_replace(100);
		assert(t[100] == 100);
		assert(t[0] == 0);
		assert(t[6] == 6);
		std::clog << " [ ok ]\n";

	}
	void iterator() {
		std::clog << "iterator :\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		std::vector<int> test;
		for (auto i : t) test.push_back(i.get_value());
		assert(test[0] == 6);
		assert(test[1] == 2);
		assert(test[3] == 4);
		assert(test[5] == 100);
		std::clog << " [ ok ]\n";

	}

}
namespace map_test {
	void no_paremeter_constructor();
	void size();
	void copy_constructor();
	void copy_operator();
	void iterator();
	void find();
	void insert_or_assign();

	void run_all() {
		std::clog << " ------- map_test-------  \n";
		size();
		no_paremeter_constructor();
		copy_constructor();
		copy_operator();
		iterator();
		find();
		insert_or_assign();
	}
	void no_paremeter_constructor() {
		std::clog << "no_parem_constructor :\t";

		my::map<int, char> m;
		m.insert(5, 'a');
		m.insert(-1, 'b');
		m.insert(8, 'c');
		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');
		m.insert(2, 'g');
		m.insert(2, 'h');
		m.insert(7, 'i');
		assert(m[5] == 'a');
		assert(m[-1] == 'b');
		assert(m[8] == 'c');
		assert(m[-2] == 'e');
		assert(m[-5] == 'f');
		assert(m[7] == 'i');

		std::clog << " [ ok ]\n";

	}
	void size() {
		std::clog << "size :\t\t\t";

		my::map<int, char> m;

		assert(m.size() == 0);
		m.insert(5, 'a');
		assert(m.size() == 1);
		m.insert(-1, 'b');
		assert(m.size() == 2);
		m.insert(8, 'c');
		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');
		m.insert(2, 'g');
		m.insert(2, 'h');
		m.insert(7, 'i');
		assert(m.size() == 8);
		std::clog << " [ ok ]\n";
	}
	void copy_constructor() {
		std::clog << "copy_constructor :\t";

		my::map<int, char> m;

		m.insert(5, 'a');
		m.insert(-1, 'b');
		m.insert(8, 'c');
		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');
		m.insert(2, 'g');
		m.insert(2, 'h');
		m.insert(7, 'i');
		my::map<int, char> g(m);
		assert(g.size() == 8);
		g.insert(0, 'i');
		assert(g.size() == 9);
		std::clog << " [ ok ]\n";
	}
	void copy_operator() {
		std::clog << "copy_operator :\t\t";

		my::map<int, char> m({ 5,'h' });

		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');

		my::map<int, char> g = m;
		assert(g[3] == 'd');
		assert(g[5] == 'h');

		std::clog << " [ ok ]\n";

	}
	void find() {
		std::clog << "find : \t\t\t";
		my::map<int, char> m({ 5,'h' });

		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');
		m.insert({ 10, 'f' });

		assert(m.find(10) == 'f');
		assert(m.find(-2) == 'e');
		std::clog << " [ ok ]\n";
	}
	void iterator() {
		my::map<int, char> m;

		m.insert(3, 'd');
		m.insert(-2, 'e');
		m.insert(-5, 'f');
		m.insert(2, 'g');
		m.insert(2, 'h');
		m.insert(7, 'i');
		m.insert_or_assign(3, 'h');
		std::vector<int> test;
		for (auto i : m) test.push_back(i.get_value().second);	//shorten that fucking thing asap
		assert(test[0] == 'h');
		assert(test[1] == 'e');

		assert(test[3] == 'g');

		std::clog << "iterator :\t\t [ ok ]\n";

	}
	void insert_or_assign() {
		std::clog << "insert_or_assign: \t";

		my::map<int, int> m;

		size_t temp = m.size();

		m.insert_or_assign(2, 4);

		m.insert_or_assign(1, 3);

		m.insert_or_assign(2, 5);


		assert(m[2] == 5);
		assert(m[1] == 3);

		assert(m.size() == 2);

		std::clog << " [ ok ] \n";

	}
}
namespace fc_test {
	void no_param_constructor();
	void copy_constructor();
	void iterator();
	void brackets_operator();

	void run_all() {
		std::clog << " ------- fc_test-------  \n";
		no_param_constructor();
		copy_constructor();
		brackets_operator();
		iterator();

	};

	void no_param_constructor() {
		FreaquencyCounter<int> f;
		f.add_data(5);
		f.add_data(5);
		f.add_data(6);
		f.add_data(7);
		auto tp = f.size();
		assert(tp == 3);
		std::clog << "size :\t\t\t [ ok ]\n";
		f.add_data(8);
		assert(f.size() == 4);
		std::clog << "add data :\t\t [ ok ]\n";
		std::clog << "no_param_constructor :\t [ ok ]\n";
	}

	void iterator() {
		FreaquencyCounter<int> f;
		f.add_data(5);
		f.add_data(5);
		f.add_data(6);
		f.add_data(7);
		std::vector<int> test;

		//for (auto i : f) test.push_back(i);
		//assert(test[0] == 5);
		//assert(test[1] == 6);
		//assert(test[2] == 7);
		//std::clog << "iterator : \t\t[ ok ]\n";

	}

	void copy_constructor() {
		FreaquencyCounter<int> f;
		f.add_data(5);
		f.add_data(5);
		f.add_data(6);
		f.add_data(7);

		FreaquencyCounter<int> g(f);
		std::vector<int> test;
		/*for (auto i : g) test.push_back(i.get_value().second);
		assert(test[0] == 5);
		assert(test[1] == 6);
		assert(test[2] == 7);*/

		assert(g.size() == 3);

		std::clog << "copy_constructor : \t [ ok ]\n";

	}

	void brackets_operator() {

		FreaquencyCounter<int> f;
		f.add_data(5);
		f.add_data(3);
		f.add_data(2);

		assert(f[3] == 1);
		assert(f[5] == 1);
		assert(f[2] == 1);


		std::clog << "brackets_operator : \t [ ok ]\n";

	}

}

#define DEBUG false 

int main()
{

#if DEBUG // podstawowe testy 
	tree_test::run_all();
	map_test::run_all();
	fc_test::run_all();
#else
	srand(time(NULL));

	FreaquencyCounter<wchar_t> biblia_pl;
	FreaquencyCounter<char> biblia_eng;
	FreaquencyCounter<wchar_t> biblia_it;
	FreaquencyCounter<std::wstring> slowa_biblia_pl;

	FreaquencyCounter<pixel_24bit> lena;
	FreaquencyCounter<int> los;

	std::cout << "loading biblia_pl...";
	get_characters("biblia-pl_ksiega_rdzaju.txt", biblia_pl);
	biblia_pl.create("znaki_pl.txt");

	printf("\33[2K\r"); // szybkie czyszczenie lini w konsoli i powrot na jej poczatek
	

	std::cout << "biblia_pl \t[ ok ] \trozmiar: " << biblia_pl.size() << std::endl;

	std::cout << "loading biblia_eng...";
	get_characters<char>("biblia-en.txt", biblia_eng);
	biblia_eng.create("znaki_eng.txt");

	printf("%c[2K\r", 27);

	std::cout << "biblia_eng \t[ ok ] \trozmiar: " << biblia_eng.size() << std::endl;


	std::cout << "loading biblia_it...";
	get_characters<wchar_t>("biblia-it.txt", biblia_it);
	biblia_it.create("znaki_it.txt");

	printf("%c[2K\r", 27);
	
	std::cout << "biblia_it \t[ ok ] \trozmiar: " << biblia_it.size() << std::endl;



	std::cout << "loading slowa_biblia_pl...";
	get_characters<std::wstring>("biblia-pl_ksiega_rdzaju.txt", slowa_biblia_pl);
	slowa_biblia_pl.create("slowa_pl.txt");
	printf("%c[2K\r", 27);
	

	std::cout << "slowa_biblia_pl [ ok ] \trozmiar: " << slowa_biblia_pl.size() << std::endl;


	std::cout << "loading lena...";
	get_characters<pixel_24bit>("lena.ppm", lena);
	lena.create("lena.txt");
	printf("%c[2K\r", 27);
	
	std::cout << "lena \t\t[ ok ] \trozmiar: " << lena.size() << std::endl;




	std::cout << "loading random numbers...";
	for (int i = 0; i < 1000000; i++)
	{
		los.add_data(rand() % 999 + 1);
	}
	printf("%c[2K\r", 27);

	std::cout << "saving random numbers...";
	los.gen_img(1250, "outputIMG.ppm");

	los.create("los.txt");
	printf("%c[2K\r", 27);
	std::cout << "random numbers \t[ ok ]" << std::endl;
#endif
	return 0;
}


