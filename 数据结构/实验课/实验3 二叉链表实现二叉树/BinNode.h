/*
created by David on 2019.10.20
*/
#ifndef _BINNODE_H
#define _BINNODE_H
using namespace std;

template<typename E>
class BinNode {
	public:
		~BinNode() {}

	    // Return the Node's Value
	    E &getelem();
	
	    // Set the Node's Value
	    void setelem(const E &);
	
	    // Return the Node's Left child
	    BinNode *left();
	
	    // Set the Node's Left child
	    void setleft(BinNode *);
	
	    // Return the Node's Right child
	    BinNode *right();
	
	    // Set the Node's Right child
	    void setright(BinNode *);
	
	    // Return true if the node is a leaf
	    bool isLeaf();
		
};
#endif
