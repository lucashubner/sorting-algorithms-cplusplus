#include <vector>
using std::vector;


template <typename Type> 
class Sorting {

	int QuickSortPartition(vector<Type> & vect, int left, int right, int pivot){
		while ( left <= right ){
			while( vect[left]  < pivot ) left++;
			while( vect[right] > pivot ) right--;
			if( left <= right ) {
				std::swap(vect[left], vect[right]);
				left++;
				right--;
			}
		}
		return left;
	}

	void QuickSort(vector<Type> & vect, int left, int right){
		if ( left >= right ) return;

		int pivot = vect[(left+right)/2];
		int index = QuickSortPartition(vect, left, right, pivot);

		QuickSort(vect, left, index-1);
		QuickSort(vect, index, right);

	}

	public:
	/* 
	 * Selection Sort
	 * Worst-case performance        O(n^{2}) comparisons, O(n) swaps
	 * Best-case performance         O(n^{2}) comparisons, O(1) swap
	 * Average performance           O(n^{2}) comparisons, O(n) swaps
	 * Worst-case space complexity   O(1) auxiliary
	 */
	void Selection (vector<Type> & vect){
		for( unsigned int i = 0; i < vect.size()-1; i++ ){
			unsigned int min = i;
			for(unsigned int j = i+1; j < vect.size(); j++){
				if ( vect[min] > vect[j] ){
					min = j;
				}
			}
			if ( min != i ){
				std::swap(vect[i], vect[min]);
			}
		}
	}
	/*
	 * Insertion Sort
	 * Worst-case performance      O(n^{2}) comparisons and swaps
	 * Best-case performance       O(n) comparisons, O(1) swaps
	 * Average performance         O(n^{2}) comparisons and swaps
	 * Worst-case space complexity O(n) total, O(1) auxiliary
	 */
	void Insertion (vector<Type> & vect){
		for( unsigned int i = 0; i < vect.size()-1; i++ ) {
			int j = i+1;

			while( j > 0 &&  vect[j] < vect[j-1] ){
				std::swap(vect[j], vect[j-1]);
				j--;
			}
		}
	}

	/*
	 * Bubble Sort
	 * Worst-case performance       O(n^{2}) comparisons, O(n^{2}) swaps
	 * Best-case performance        O(n) comparisons, O(1) swaps
	 * Average performance          O(n^{2}) comparisons, O(n^{2}) swaps
	 * Worst-case space complexity  O(n) total, O(1) auxiliary
	 */

	void Bubble (vector<Type> & vect){
		for(unsigned int i = 0; i < vect.size();  i++ ) {
			bool swaped = false;
			for( unsigned int j = vect.size()-1; j > i; j -- ) {
				if( vect[j] < vect[j-1] ){
					std::swap(vect[j], vect[j-1]);
					swaped = true;
				}
			}
			if ( !swaped ) return;
		}
	}
	

	/*
	 *
	 * Worst-case performance       O(n^{2})
	 * Best-case performance        O(n\log n) (simple partition)
	 *                              or O(n) (three-way partition and equal keys)
	 * Average performance          O(n\log n)
	 * Worst-case space complexity  O(n) auxiliary (naive)
	 *                              O(\log n) auxiliary (Hoare 1962)
	 */
	void Quick     (vector<Type> & vect){
		QuickSort(vect, 0, vect.size()-1);
	}

	void Merge     (vector<Type> & vect){

	}
	void Heap      (vector<Type> & vect);


};

