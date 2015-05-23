//
//  main.cpp
//  HashMap
//  Simple Template based HashTable implementation
//
//  Created by Syed Naqvi on 5/21/15.
//  Copyright (c) 2015 Naqvi. All rights reserved.
//

#include <iostream>
#include "HashMap.h"
using namespace std;

int main(int argc, const char * argv[]) {
	Hashtable<Record, string> table(1);

	Record r("A", "Stanford");
	HashTableNode<Record, string> node(r, "San Jose");
	table.insert(node);
	
	Record r1("B", "Stanford");
	HashTableNode<Record, string> node1(r1, "San Mateo");
	table.insert(node1);
	
	Record r2("C", "Stanford");
	HashTableNode<Record, string> node2(r2, "Santa Clara");
	table.insert(node2);
	
	
	Record r3("D", "Stanford");
	HashTableNode<Record, string> node3;
	node3.mKey = r3;
	node3.mValue = "SugarSync";
	table.insert(r3, "SugarSync");
	
	table.remove(r);
	
	cout<<"exists: "<<table.exists(r3)<<endl;
	
	Record r5("E", "Gilroy");
	HashTableNode<Record, string> node5(r5, "Gilroy");
	
	cout<<"exists: "<<table.exists(r5)<<endl;
	
	cout<<"Value: "<<table.Value(r3)<<endl;
	
	
    return 0;
}
