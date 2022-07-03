//STL(standard template libary):标准模板库
//六大部件：Containers（容器） Allocators（分配器） Algorithms（算法） Iterators（迭代器） Adapters（适配器） Functions（仿函数）

//Containers（容器）:
//sequence container（顺序容器）: array/vector/deque/list/forward-list
//associative container（关联容器）: set/multiset map/multimap: 内部实现看编译器，一般为红黑树（高度平衡二叉树）
//unordered container（本质上属于关联容器） : hashtable seperate chaining

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cmath>

using namespace std;

long get_a_target_long() {
	long target = 0;
	cout << "target(0-" << RAND_MAX << ")" << endl;
	cin >> target;
	return target;
}

string get_a_target_string() {
	int target = 0;
	char buf[10];
	cout << "target(0-" << RAND_MAX << ")" << endl;
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b) {
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b) {
	if (*(string*)a > * (string*)b) return 1;
	else if (*(string*)a < *(string*)b) return -1;
	else return 0;
}

#include <array>
#include <ctime>

// array
namespace jj01 {
	void test_array() {
		const int ASIZE = 100000;
		cout << "\ntest_array()...\n";
		array<long, ASIZE> c;
		clock_t timeStart = clock();
		for (long i = 0; i < ASIZE; i++) {
			c[i] = rand();
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "array.size() = " << c.size() << endl;
		cout << "array.front() = " << c.front() << endl;
		cout << "array.back() = " << c.back() << endl;
		cout << "array.data() = " << c.data() << endl;

		long target = get_a_target_long();

		timeStart = clock();
		qsort(c.data(), ASIZE, sizeof(long), compareLongs);
		long* pItem = (long*)bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs);
		cout << "qsort()+bsearch(), milli-seconds: " << clock() - timeStart << endl;
		if (pItem != NULL) {
			cout << "Found, " << *pItem << endl;
		}
		else cout << "Not found." << endl;

	}
}

#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>

// vector
namespace jj02 {
	void test_vector(long& value) {
		cout << "\ntest_vector...\n";
		vector<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& e) {
				cout << "i = " << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "vector.size(): " << c.size() << endl;
		cout << "vector.capacity(): " << c.capacity() << endl;
		cout << "vector.front(): " << c.front() << endl;
		cout << "vector.back(): " << c.back() << endl;
		cout << "vector.data(): " << c.data() << endl;

		string target = get_a_target_string();
		{
			// 1. find: C++标准库，循序查找
			timeStart = clock();
			// ::代表全局
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds: " << clock() - timeStart << endl;

			if (pItem != c.end()) {
				cout << "Found, " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
		{
			// sort() + bsearch()
			timeStart = clock();
			sort(c.begin(), c.end());
			string* pItem = (string*)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
			cout << "sort() + bsearch(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != NULL) {
				cout << "Found, " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}

	}
}

#include <list>

namespace jj03 {
	void test_list(long& value) {
		cout << "\ntest_list...\n";
		list<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "list.size(): " << c.size() << endl;
		cout << "list.max_size(): " << c.max_size() << endl;
		cout << "list.front(): " << c.front() << endl;
		cout << "list.back(): " << c.back() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "Found: " << *pItem << endl;
		}
		else cout << "Not found!" << endl;

		timeStart = clock();
		c.sort();
		cout << "sort(), milli-seconds: " << clock() - timeStart << endl;
	}
}

#include <forward_list>
// forward_list 单向链表
namespace jj04 {
	void test_forward_list(long& value) {
		cout << "\ntest_forward_list\n";
		forward_list<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				//snprintf(buf, 10, "%d", rand());
				//c.push_front(string(buf));
				c.push_front(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "forward_list.max_size(): " << c.max_size() << endl;
		cout << "forward_list.front(): " << c.front() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "Found: " << *pItem << endl;
		}
		else {
			cout << "Not found!" << endl;
		}
		timeStart = clock();
		c.sort();
		cout << "sort(), milli-seconds: " << clock() - timeStart << endl;
	}
}

#include <deque>
// deque 双端队列

namespace jj05 {
	void test_deque(long& value) {
		cout << "\ntest_deque...\n";
		deque<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "deque.size(): " << c.size() << endl;
		cout << "deque.front(): " << c.front() << endl;
		cout << "deque.back(): " << c.back() << endl;
		cout << "deque.max_size(): " << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find, milli-seconds: " << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "Found: " << *pItem << endl;
		}
		else cout << "Not Found!" << endl;

		timeStart = clock();
		sort(c.begin(), c.end());
		cout << "sort(), milli-seconds: " << clock() - timeStart << endl;
	}
}

#include <set>
// 关联容器（查找速度快），multiset, 可以存在重复元素，内部实现：（看编译器）一般为红黑树
namespace jj06 {
	void test_multiset(long& value) {
		cout << "\ntest_multiset...\n";
		multiset<string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "multiset.size(): " << c.size() << endl;
		cout << "multiset.max_size(): " << c.max_size() << endl;

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <map>
// 关联容器（查找速度快），multimap, 内部实现：（看编译器）一般为红黑树
namespace jj07 {
	void test_multimap(long& value) {
		cout << "\ntest_multimap...\n";
		multimap<long, string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				// multimap 不可以使用[]作insert
				c.insert(pair<long, string>(i, to_string(rand())));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "multimap.size(): " << c.size() << endl;
		cout << "multimap.max_size(): " << c.max_size() << endl;

		long target = get_a_target_long();
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << (*pItem).second << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <unordered_set>
// unordered_multiset, 内部实现：hash_table

namespace jj08 {
	void test_unordered_multiset(long& value) {
		cout << "\ntest_unordered_multiset...\n";
		unordered_multiset<string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "unordered_multiset.size(): " << c.size() << endl;
		cout << "unordered_multiset.max_size(): " << c.max_size() << endl;
		// bucket_count, hash_table中地址个数
		cout << "unordered_multiset.bucket_count(): " << c.bucket_count() << endl;
		cout << "unordered_multiset.load_factor(): " << c.load_factor() << endl;
		cout << "unordered_multiset.max_load_factor(): " << c.max_load_factor() << endl;
		cout << "unordered_multiset.max_bucket_count(): " << c.max_bucket_count() << endl;

		for (unsigned i = 0; i < 20; i++) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements." << endl;
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <unordered_map>
// unordered_multimap, 内部实现：hash_table
namespace jj09 {
	void test_unordered_multimap(long& value) {
		cout << "\ntest_unordered_multimap...\n";
		unordered_multimap<long, string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.insert(pair<long, string>(i, to_string(rand())));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "unordered_multimap.size(): " << c.size() << endl;
		cout << "unordered_multimap.max_size(): " << c.max_size() << endl;

		long target = get_a_target_long();
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << (*pItem).second << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <set>
// set,元素唯一，内部实现：（看编译器）一般为红黑树
namespace jj13 {
	void test_set(long& value) {
		cout << "\ntest_set...\n";
		set<string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "set.size(): " << c.size() << endl;
		cout << "set.max_size(): " << c.max_size() << endl;

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <map>
// map, 内部实现：（看编译器）一般为红黑树
namespace jj14 {
	void test_map(long& value) {
		cout << "\ntest_map...\n";
		map<long, string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				// multimap 不可以使用[]作insert
				// map可以直接使用[]作insert
				//c.insert(pair<long, string>(i, to_string(rand())));
				c[i] = to_string(rand());
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "map.size(): " << c.size() << endl;
		cout << "map.max_size(): " << c.max_size() << endl;

		long target = get_a_target_long();
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << (*pItem).second << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <unordered_set>
// unordered_set, 内部实现：hash_table

namespace jj15 {
	void test_unordered_set(long& value) {
		cout << "\ntest_unordered_set...\n";
		unordered_set<string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.insert(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "unordered_set.size(): " << c.size() << endl;
		cout << "unordered_set.max_size(): " << c.max_size() << endl;
		// bucket_count, hash_table中地址个数
		cout << "unordered_set.bucket_count(): " << c.bucket_count() << endl;
		cout << "unordered_set.load_factor(): " << c.load_factor() << endl;
		cout << "unordered_set.max_load_factor(): " << c.max_load_factor() << endl;
		cout << "unordered_set.max_bucket_count(): " << c.max_bucket_count() << endl;

		for (unsigned i = 0; i < 20; i++) {
			cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements." << endl;
		}

		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << *pItem << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <unordered_map>
// unordered_map, 内部实现：hash_table
namespace jj16 {
	void test_unordered_map(long& value) {
		cout << "\ntest_unordered_map...\n";
		unordered_map<long, string> c;
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				//c.insert(pair<long, string>(i, to_string(rand())));
				c[i] = to_string(rand());
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "unordered_map.size(): " << c.size() << endl;
		cout << "unordered_map.max_size(): " << c.max_size() << endl;

		long target = get_a_target_long();
		{
			timeStart = clock();
			auto pItem = c.find(target);
			cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
			if (pItem != c.end()) {
				cout << "Found: " << (*pItem).second << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
		}
	}
}

#include <stack>
// stack 内部容器deque，严格来讲不算容器，而是容器的适配器adapter
namespace jj17 {
	void test_stack(long& value) {
		cout << "\ntest_stack\n";
		stack<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.push(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "stack.size(): " << c.size() << endl;
		cout << "stack.top(): " << c.top() << endl;
		c.pop();
		cout << "stack.size(): " << c.size() << endl;
		cout << "stack.top(): " << c.top() << endl;
	}
}

#include <queue>
// queue 内部容器deque，严格来讲不算容器，而是容器的适配器adapter
namespace jj18 {
	void test_queue(long& value) {
		cout << "\ntest_queue\n";
		queue<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				c.push(to_string(rand()));
			}
			catch (exception& e) {
				cout << "i=" << e.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds: " << clock() - timeStart << endl;
		cout << "queue.size(): " << c.size() << endl;
		cout << "queue.front(): " << c.front() << endl;
		cout << "queue.back(): " << c.back() << endl;
		c.pop();
		cout << "queue.size(): " << c.size() << endl;
		cout << "queue.front(): " << c.front() << endl;
		cout << "queue.back(): " << c.back() << endl;
	}
}

void showmenu()
{
	cout << "please enter:\n"
		"0)quit\n"
		"1)test_array					2)test_vector\n"
		"3)test_list					4)test_forward_list\n"
		"5)test_deque					6)test_multiset\n"
		"7)test_multimap					8)test_unordered_multiset\n"
		"9)test_unordered_multimap			10)test_ \n"
		"13)test_set					14)test_map\n"
		"15)test_unordered_set				16)test_unordered_map\n"
		"17)test_stack					18)test_queue\n";
}


//int main() {
//	showmenu();
//	int choice;
//	cin >> choice;
//	while (choice != 0) {
//		switch (choice) {
//		case 1:
//			cout << "select: " << choice << endl;
//			jj01::test_array();
//			break;
//		case 2:
//			cout << "select: " << choice << endl;
//			long value2;
//			cout << "elements number:";
//			cin >> value2;
//			jj02::test_vector(value2);
//			break;
//
//		case 3:
//			cout << "select: " << choice << endl;
//			long value3;
//			cout << "elements number: ";
//			cin >> value3;
//			jj03::test_list(value3);
//			break;
//
//		case 4:
//			cout << "select: " << choice << endl;
//			long value4;
//			cout << "elements number: ";
//			cin >> value4;
//			jj04::test_forward_list(value4);
//			break;
//
//		case 5:
//			cout << "select: " << choice << endl;
//			long value5;
//			cout << "elements number: ";
//			cin >> value5;
//			jj05::test_deque(value5);
//			break;
//
//		case 6:
//			cout << "select: " << choice << endl;
//			long value6;
//			cout << "elements number: ";
//			cin >> value6;
//			jj06::test_multiset(value6);
//			break;
//
//		case 7:
//			cout << "select: " << choice << endl;
//			long value7;
//			cout << "elements number: ";
//			cin >> value7;
//			jj07::test_multimap(value7);
//			break;
//
//		case 8:
//			cout << "select: " << choice << endl;
//			long value8;
//			cout << "elements number: ";
//			cin >> value8;
//			jj08::test_unordered_multiset(value8);
//			break;
//
//		case 9:
//			cout << "select: " << choice << endl;
//			long value9;
//			cout << "elements number: ";
//			cin >> value9;
//			jj09::test_unordered_multimap(value9);
//			break;
//
//		case 13:
//			cout << "select: " << choice << endl;
//			long value13;
//			cout << "elements number: ";
//			cin >> value13;
//			jj13::test_set(value13);
//			break;
//
//		case 14:
//			cout << "select: " << choice << endl;
//			long value14;
//			cout << "elements number: ";
//			cin >> value14;
//			jj14::test_map(value14);
//			break;
//
//		case 15:
//			cout << "select: " << choice << endl;
//			long value15;
//			cout << "elements number: ";
//			cin >> value15;
//			jj15::test_unordered_set(value15);
//			break;
//
//		case 16:
//			cout << "select: " << choice << endl;
//			long value16;
//			cout << "elements number: ";
//			cin >> value16;
//			jj16::test_unordered_map(value16);
//			break;
//
//		case 17:
//			cout << "select: " << choice << endl;
//			long value17;
//			cout << "elements number: ";
//			cin >> value17;
//			jj17::test_stack(value17);
//			break;
//
//		case 18:
//			cout << "select: " << choice << endl;
//			long value18;
//			cout << "elements number: ";
//			cin >> value18;
//			jj18::test_queue(value18);
//			break;
//
//		default:
//			cout << "quit." << endl;
//			break;
//		}
//		cout << "Select choice: ";
//		cin >> choice;
//	}
//	return 0;
//}