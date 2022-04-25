/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int ptr = 0;
    vector<int> arr;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    this->arr = nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return arr[ptr];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int p = arr[ptr];
        ptr++;
        return p;
	}
	
	bool hasNext() const {
	    return arr.size() > ptr;
	}
};