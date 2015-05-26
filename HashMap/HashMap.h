//
//  HashMap.h
//  HashMap
//
//  Created by Syed Naqvi on 5/21/15.
//  Copyright (c) 2015 Naqvi. All rights reserved.
//

#ifndef __HashMap__HashMap__
#define __HashMap__HashMap__

#include <iostream>

class Record{
public:
	Record();
	Record(const std::string& name, const std::string& school);
	operator int();
	bool operator == (const Record& obj);
	bool operator != (const Record& obj);
	
	std::string name;
	std::string school;
};

template <class K, class V>
struct HashTableNode{
	K mKey;
	V mValue;
	
	HashTableNode():mKey(),
					mValue(),
					mNext(NULL){
	}
	
	HashTableNode(K key, V value):mKey(key),
								  mValue(value),
								  mNext(NULL){
	}
	
	HashTableNode<K, V> *mNext;
};

template <class K, class V>
class Hashtable{
	
private:
	int hash(K key){
		return key % m_size;
	}
	
public:
	Hashtable(int size):m_size(size),
						m_buckets(NULL){

		m_buckets = new HashTableNode<K, V>*[m_size];
		for(int i=0; i<m_size; i++)
			m_buckets[i] = NULL;
	}
	
	~Hashtable(){
		for (int i=0; i<m_size; i++)
			delete m_buckets[i];
	}
	
	bool insert(const K& key, const V& value){
		int index = this->hash(key);
		if(m_buckets[index] == NULL){
			HashTableNode<K, V>* node = new HashTableNode<K, V>(key, value);
//			node->mKey = key;
//			node->mValue = value;
			m_buckets[index] = node;
		} else {
			HashTableNode<K, V> *currNode = m_buckets[index];
			while(currNode->mNext != NULL){
				currNode = currNode->mNext;
			}
			currNode->mNext = new HashTableNode<K, V>(key, value);
		}
		
		return true;
	}
	
	bool insert(const HashTableNode<K, V>& node){
		int index = this->hash(node.mKey);
		if(m_buckets[index] == NULL){
			m_buckets[index] = new HashTableNode<K, V>(node);
		} else {
			HashTableNode<K, V> *currNode = m_buckets[index];
			while(currNode->mNext != NULL){
				currNode = currNode->mNext;
			}
			currNode->mNext = new HashTableNode<K, V>(node);
		}
		
		return true;
	}
	
	HashTableNode<K, V>* find(const K& key){
		int index = hash(key);
		HashTableNode<K, V>* node = m_buckets[index];
		if(node == NULL)
			return NULL;
		
		if(node->mKey == key){
			return node;
		} else {
			HashTableNode<K, V>* currNode = node->mNext;
			while(currNode != NULL && currNode->mKey != key){
				currNode = currNode->mNext;
			}
			if(currNode != NULL)
				return currNode;
		}
		
		return NULL;
	}
	
	bool remove(const K& key){
		int index = hash(key);
		
		if(m_buckets[index] == NULL)
			return false;
		
		if(m_buckets[index]->mKey == key){ // head
			HashTableNode<K, V>* node = m_buckets[index];
			m_buckets[index] = m_buckets[index]->mNext;
			delete node;
			
			return true;
		} else {
			HashTableNode<K, V>* currNode = m_buckets[index]->mNext;
			HashTableNode<K, V>* prevNode = m_buckets[index];
			while(currNode != NULL){
				if(currNode->mKey == key){
					prevNode->mNext = currNode->mNext;
					delete currNode; // deleting the node
					
					return true;
				}
				currNode = currNode->mNext;
				prevNode = prevNode->mNext;
			}
		}
		
		return false;
	}
	
	V Value(const K& key){
		HashTableNode<K, V>* node = find(key);
		if(node != NULL)
			return node->mValue;
		
		return V();
	}
	
	bool exists(const K& key){
		return find(key) != NULL;
	}
	
private:
	HashTableNode<K, V> **m_buckets; // can use vectors here too.
	int m_size;
};

#endif /* defined(__HashMap__HashMap__) */
