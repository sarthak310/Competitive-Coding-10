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

//time: O(1)
//space: O(1)
class PeekingIterator : public Iterator {
    int next_val; // keep a variable for storing the "next value" for use in "peek" function
    bool iter_hasnext; // for storing the "has next value"
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    iter_hasnext=Iterator::hasNext(); // store current has_next value
	    if (iter_hasnext)
            next_val = Iterator::next(); // store the "next_val" for "future" use in "peek" function
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val; // return current next_val
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int curr_next = next_val; // store the current next for returning
        
        iter_hasnext=Iterator::hasNext(); // change the iter_hasnext variable
	    if (iter_hasnext) 
            next_val = Iterator::next(); // change the next_val and move the iterator to next position
        
	    return curr_next; // return the previously stored current next
	}
	
	bool hasNext() const {
	    return iter_hasnext; // return current iter_hashnext value
	}
};