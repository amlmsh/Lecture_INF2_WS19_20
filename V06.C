/*
 * V06.C
 *
 *  Created on: 20.06.2018
 *      Author: aml
 */

#include "V06.H"

namespace V06{

Numbers::~Numbers() {
	delete [] dataField_;
};

void Numbers::sort(){
	int tmp;
	bool swaped;
	do{
		swaped = false;
		for(int i = 1; i < size_; i++){
			if(dataField_[i-1] > dataField_[i]){
				tmp = dataField_[i];
				dataField_[i] = dataField_[i-1];
				dataField_[i-1] = tmp;
				swaped = true;
			}
		}
	}while(swaped);
	return;
}


void Numbers::print() {
	cout << "[";
	if (dataField_ != NULL) {
		for (int i = 0; i < (size_ - 1); i++) {
			cout << dataField_[i] << ", ";
		};
		cout << dataField_[size_ - 1];
	};
	cout << "]";
};


void Numbers::init(int n) {
	dataField_ = new int[n];
	size_ = n;
	for(int i=0; i < size_; i++){
		dataField_[i] = rand() % size_;
	}
};

void Numbers::set(int idx, int value) {
	dataField_[idx] = value;
};

int Numbers::get(int idx) {
	return dataField_[idx];
};

void SelectionSort::sort(){
	cout << "selection sort\n";
	bool swaped = false;
	int minPos, tmp;
	for(int i = 0; i < (size_ - 1); i++){
		minPos = i;
		for(int j = (i + 1); j < size_; j++){
			if(dataField_[j] < dataField_[minPos]){
				minPos = j;
				swaped = true;
			}
		}
		if(swaped){
			tmp = dataField_[i];
			dataField_[i] = dataField_[minPos];
			dataField_[minPos] = tmp;
		}
	}
}

void MergeSort::sort(){
	return (mergeSort(0, size_ - 1));
}


void MergeSort::mergeSort(int l, int r){
	int m;
	// split, let it sort and merge
	if(l < r){
		// split
		m = l + ((r-l) / 2);
		// sort the sub-lists
		mergeSort(l,m );
		mergeSort(m+1,r);
		//merge the sorted sub-lists [l,m] with [m+1,r]
		merge(l, m, r);
	}
	return;
}

void MergeSort::merge(int l, int m, int r){
	int tmpSize = (r-l) + 1;
	int tmpList[tmpSize];

	int tmpListIdx = 0;
	int lIdx = l;
	int rIdx = m+1;

	while((lIdx <= m) && (rIdx <= r)){
		if( dataField_[lIdx] < dataField_[rIdx]){
			tmpList[tmpListIdx] = dataField_[lIdx];
			lIdx++;
		}else{
			tmpList[tmpListIdx] = dataField_[rIdx];
			rIdx++;
		}
		tmpListIdx++;
	}

	while(lIdx <= m){
		tmpList[tmpListIdx] = dataField_[lIdx];
		lIdx++;
		tmpListIdx++;
	}

	while(rIdx <= r){
		tmpList[tmpListIdx] = dataField_[rIdx];
		rIdx++;
		tmpListIdx++;
	}

	for(int i=0; i < tmpSize; i++){
		dataField_[l + i] = tmpList[i];
	}
	return;
}

}

void demoV06_00(){
	using namespace V06;

	A a;
	B b;
	C c;

	a.out();
	b.out();
	c.out();

	vA va;
	vB vb;
	vC vc;

	va.out();
	vb.out();
	vc.out();

	A  *ptrA;
	vA *ptrVA;

	ptrA = &a;
	ptrA->out();
	ptrA = &b;
	ptrA->out();
	ptrA = &c;
	ptrA->out();


	ptrVA = &va;
	ptrVA->out();
	ptrVA = &vb;
	ptrVA->out();
	ptrVA = &vc;
	ptrVA->out();

}



void demoV06_01(){
	using namespace V06;

	Employee e;
	Manager  m;
	Director d;

	Manager mans[13];
	d.managers_ = mans;
	d.managers_[1] = m;

}


