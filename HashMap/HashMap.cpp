//
//  HashMap.cpp
//  HashMap
//
//  Created by Syed Naqvi on 5/21/15.
//  Copyright (c) 2015 Naqvi. All rights reserved.
//

#include "HashMap.h"

using namespace std;

Record::Record():name(),
				school(){
}

Record::Record(const std::string& name, const std::string& school){
	this->name = name;
	this->school = school;
}

Record::operator int(){
	int hash = 0;
	for(int i=0; i<name.length(); i++)
		hash += (int)name[i];
		
		for(int j=0; j<school.length(); j++)
			hash += (int)school[j];
			
			return hash;
}

bool Record::operator == (const Record& obj){
	if(this->name == obj.name &&
	   this->school == obj.school)
		return true;
	return false;
}

bool Record::operator != (const Record& obj){
	return !(*this == obj);
}