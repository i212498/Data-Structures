// this code is very badly written but works 100% to my knowledge. For the sake of your sanity do not attempt to read the code.

#pragma once
#include <iostream>
#include "QueueforRBTree.h"

using namespace std;


namespace rb
{

template <typename T>

struct Node
{
	T val;
	char colour;		// if b its black, if r its red
	Node<T>* left;
	Node<T>* right;
};

template <typename T>

class Tree
{
private:

	Node<T>* root;

	void RR_Rotation(Node<T>*& temp)
	{

		Node<T>* temp2 = temp;

		temp = temp->left;

		temp2->left = temp->right;

		temp->right = temp2;

	}

	void LL_Rotation(Node<T>*& temp)
	{
		Node<T>* temp2 = temp;

		temp = temp->right;

		temp2->right = temp->left;

		temp->left = temp2;

	}

	void balanceTree(Node<T>* &temp)
	{
		if (temp != NULL && temp->colour == 'b')		// p[p[z]]
		{
			// when z, p[z], uncle y are red 

			if (temp->left != NULL && temp->right != NULL)						// p[z] and uncle y
			{
				if (temp->left->colour == 'r' && temp->right->colour == 'r')
				{

					if (temp->left->left != NULL)						// when p[z] is left child and z is left child
					{
						if (temp->left->left->colour == 'r')
						{
							if (temp != root)
							{
								temp->colour = 'r';
							}

							temp->left->colour = 'b';
							temp->right->colour = 'b';

						}
					}

					if (temp->left->right != NULL)						// when p[z] is left child and z is right child
					{
						if (temp->left->right->colour == 'r')
						{
							if (temp != root)
							{
								temp->colour = 'r';
							}

							temp->left->colour = 'b';
							temp->right->colour = 'b';

						}
					}

					
					if (temp->right->right != NULL)						// when p[z] is right child and z is right child
					{
						if (temp->right->right->colour == 'r')
						{
							if (temp != root)
							{
								temp->colour = 'r';
							}

							temp->left->colour = 'b';
							temp->right->colour = 'b';

						}
					}

					if (temp->right->left != NULL)						// when p[z] is right child and z is left child
					{
						if (temp->right->left->colour == 'r')
						{
							if (temp != root)
							{
								temp->colour = 'r';
							}

							temp->left->colour = 'b';
							temp->right->colour = 'b';

						}
					}


				}
			}

			// when z, p[z] are red and uncle y is black/NIL and p[z] is left child

			if (temp->left != NULL)					// p[z]
			{
				if (temp->left->colour == 'r')
				{
					if (temp->right != NULL)		// uncle y
					{
						if (temp->right->colour == 'b')
						{
											
							if (temp->left->right != NULL)		// z is right child
							{
								if (temp->left->right->colour == 'r')
								{
									LL_Rotation(temp->left);	// left rotate p[z]
								}
							}

							if (temp->left->left != NULL)		// z is left child
							{
								if (temp->left->left->colour == 'r')
								{
									Node<T>* doubleparent = temp;

									Node<T>* parent = temp->left;

									RR_Rotation(temp);		// right rotate p[ p[z] ]

									doubleparent->colour = 'r';

									parent->colour = 'b';
									
									
								}
							}
						}
					}

					if (temp->right == NULL)		// uncle y
					{
						if (temp->left->right != NULL)
						{
							if (temp->left->right->colour == 'r')
							{
								LL_Rotation(temp->left);	// left rotate p[z]
							}

						}

						if (temp->left->left != NULL)		// z is left child
						{
							if (temp->left->left->colour == 'r')
							{
								Node<T>* doubleparent = temp;

								Node<T>* parent = temp->left;

								RR_Rotation(temp);		// right rotate p[ p[z] ]

								doubleparent->colour = 'r';

								parent->colour = 'b';

						
							}
						}
					}
				}
			}

			// when z, p[z] are red and uncle y is black/NIL and p[z] is right child

			if (temp->right != NULL)
			{
				if (temp->right->colour == 'r')
				{
					
					if (temp->left != NULL)		// uncle y
					{
						if (temp->left->colour == 'b')
						{
							if (temp->right->left != NULL)		// z is left child
							{
								if (temp->right->left->colour == 'r')
								{
									RR_Rotation(temp->right);	// right rotate p[z]
								}
							}
							

							if (temp->right->right != NULL)		// z is right child
							{
								if (temp->right->right->colour == 'r')
								{
									Node<T>* doubleparent = temp;

									Node<T>* parent = temp->right;

									LL_Rotation(temp);

									doubleparent->colour = 'r';

									parent->colour = 'b';
								}
							}

							
						}
					}

					
					if (temp->left == NULL)		// uncle y
					{
						if (temp->right->left != NULL)		// z is left child
						{
							if (temp->right->left->colour == 'r')
							{
								RR_Rotation(temp->right);	// right rotate p[z]
							}
						}


						if (temp->right->right != NULL)		// z is right child
						{
							if (temp->right->right->colour == 'r')
							{
								Node<T>* doubleparent = temp;

								Node<T>* parent = temp->right;

								LL_Rotation(temp);

								doubleparent->colour = 'r';

								parent->colour = 'b';
							}
						}
					}
				}
			}
			
		}
	}

	void insertnode(T val, Node<T>*& temp)
	{
		if (temp == NULL && temp == root)
		{
			temp = new Node<T>;
			temp->val = val;
			temp->colour = 'b';
			temp->left = NULL;
			temp->right = NULL;

		}

		else if (temp == NULL && temp != root)
		{
			temp = new Node<T>;
			temp->val = val;
			temp->colour = 'r';
			temp->left = NULL;
			temp->right = NULL;

		}

		else
		{
			
			if (val < temp->val)
			{
				insertnode(val, temp->left);

				balanceTree(temp);

			}

			if (val > temp->val)
			{
				insertnode(val, temp->right);

				balanceTree(temp);
			}

		}
		
	}

	bool retrieveval(T val, Node<T>*& temp)
	{
		if (temp == NULL)
		{
			return false;
		}
		else
		{
			if (temp->val == val)
			{
				return true;
			}

			if (val < temp->val)
			{
				return retrieveval(val, temp->left);
			}

			if (val > temp->val)
			{
				return retrieveval(val, temp->right);
			}

		}
	}

	void InOrder(Node<T>* &temp)
	{
		if (temp != NULL)
		{
			InOrder(temp->left);
			cout << temp->val << " ";
			InOrder(temp->right);
		}
	}

	void PreOrder(Node<T>* temp)
	{
		if (temp != NULL)
		{
			cout << temp->val << " ";
			PreOrder(temp->left);
			PreOrder(temp->right);
		}
	}

	void PostOrder(Node<T>* temp)
	{
		if (temp != NULL)
		{
			PostOrder(temp->left);
			PostOrder(temp->right);
			cout << temp->val << " ";
		}
	}

	void BFSearch(Node<T>* temp)
	{
		if (root == NULL)
		{
			return;
		}

		RBQueue<Node<T>*> Q1;

		Q1.enqueue(temp);

		while (Q1.isEmpty() != true)
		{
			temp = Q1.Front();

			if (temp->left != NULL)
			{
				Q1.enqueue(temp->left);
			}
			
			if (temp->right != NULL)
			{
				Q1.enqueue(temp->right);
			}

			cout << Q1.Front()->val << "(" << Q1.Front()->colour << ") ";

			Q1.dequeue();
		}
		
	}

	T findMin(Node<T>* temp)
	{
		if (temp == NULL)
		{
			//return 0;		// /* will need to cater here */ //
		}

		if (temp->left == NULL)
		{
			return temp->val;
		}

		if (temp->left != NULL)
		{
			return findMin(temp->left);
		}
	}


	Node<T>*& getRef(Node<T>*& temp, T val)
	{
		if (root != NULL)
		{
			if (val == root->val)
			{
				return temp;
			}
		}

		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			if (temp->left != NULL)
			{
				if (temp->left->val == val)
				{
					return temp->left;
				}
			}
			
			if (temp->right != NULL)
			{
				if (temp->right->val == val)
				{
					return temp->right;
				}
			}
			

			if (temp->val < val)
			{
				return getRef(temp->right, val);
			}

			if (temp->val > val)
			{
				return getRef(temp->left, val);
			}

		}

	}

	Node<T>*& getParent(Node<T>*& temp, T val)
	{

		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			if (temp->left != NULL)
			{
				if (temp->left->val == val)
				{
					return temp;
				}
			}

			if (temp->right != NULL)
			{
				if (temp->right->val == val)
				{
					return temp;
				}
			}


			if (temp->val < val)
			{
				return getParent(temp->right, val);
			}

			if (temp->val > val)
			{
				return getParent(temp->left, val);
			}

		}

	}



	void deletefix(Node<T>*& parent_x, Node<T>* x)
	{
		Node<T>* p = parent_x;

		while(x != root)
		{
			if (x != NULL)
			{
				if (x->colour == 'b')
				{
					
					Node<T>* w = 0;

					if (p->left == x)
					{
						w = p->right;

						if (w != NULL)
						{
							// type 1

							if (w->colour == 'r')
							{
								w->colour = 'b';

								p->colour = 'r';

								LL_Rotation(getRef(root, p->val));

								w = p->right;

							}

							//type 2

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->left != NULL && w->right != NULL)
									{
										if (w->left->colour == 'b' && w->right->colour == 'b')
										{
											w->colour = 'r';

											x = p;

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);

										}
									}

									if (w->left == NULL && w->right == NULL)
									{
										w->colour = 'r';

										x = p;

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}


									if (w->left != NULL && w->right == NULL)
									{
										if (w->left->colour == 'b')
										{
											w->colour = 'r';

											x = p;

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);
										}
									}

									if (w->left == NULL && w->right != NULL)
									{
										if (w->right->colour == 'b')
										{
											w->colour = 'r';

											x = p;

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);
										}
									}
								}
							}


							//type 3

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->left != NULL && w->right != NULL)
									{
										if (w->left->colour == 'r' && w->right->colour == 'b')
										{
											w->left->colour = 'b';

											w->colour = 'r';

											RR_Rotation(getRef(root, w->val));


											w = getRef(root, p->val)->right;

										}
									}

									if (w->left != NULL)
									{
										if (w->left->colour == 'r')
										{
											w->left->colour = 'b';

											w->colour = 'r';

											RR_Rotation(getRef(root, w->val));

											w = getRef(root, p->val)->right;

										}
									}

								}
							}

							//type 4

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->right != NULL)
									{
										if (w->right->colour == 'r')
										{
											w->colour = p->colour;

											p->colour = 'b';

											if (w->right != NULL)
											{
												w->right->colour = 'b';
											}

											LL_Rotation(getRef(root, p->val));

											x = root;

										}
									}

								}
							}

						}

					}

					if (p->right == x)
					{
						w = p->left;
						
						if (w != NULL)
						{
							// type 1

							if (w->colour == 'r')
							{
								w->colour = 'b';

								p->colour = 'r';

								RR_Rotation(getRef(root, p->val));

								w = p->left;

							}

							//type 2

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->left != NULL && w->right != NULL)
									{
										if (w->left->colour == 'b' && w->right->colour == 'b')
										{
											w->colour = 'r';

											x = p; 

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);
										}
									}

									if (w->left == NULL && w->right == NULL)
									{
										w->colour = 'r';

										x = p; 

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}


									if (w->left != NULL && w->right == NULL)
									{
										if (w->left->colour == 'b')
										{
											w->colour = 'r';

											x = p; 

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);
										}
									}

									if (w->left == NULL && w->right != NULL)
									{
										if (w->right->colour == 'b')
										{
											w->colour = 'r';

											x = p;

											if (x == root)
											{
												break;
											}

											p = getParent(root, x->val);
										}
									}
								}
							}

							//type 3

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->left != NULL && w->right != NULL)
									{
										if (w->left->colour == 'b' && w->right->colour == 'r')
										{
											w->right->colour = 'b';

											w->colour = 'r';

											LL_Rotation(getRef(root, w->val));


											w = getRef(root, p->val)->left;

										}
									}

									if (w->right != NULL)
									{
										if (w->right->colour == 'r')
										{
											w->right->colour = 'b';

											w->colour = 'r';

											LL_Rotation(getRef(root, w->val));


											w = getRef(root, p->val)->left;

										}
									}

								}
							}

							//type 4

							if (w != NULL)
							{
								if (w->colour == 'b')
								{
									if (w->left != NULL)
									{
										if (w->left->colour == 'r')
										{
											w->colour = p->colour;

											p->colour = 'b';

											if (w->left != NULL)
											{
												w->left->colour = 'b';
											}

											RR_Rotation(getRef(root, p->val));

											x = root;

										}
									}

								}
							}

						}
						
					}

				}

				else if (x->colour == 'r')
				{
					break;
				}

			}
		
			if (x == NULL)
			{
				Node<T>* w = 0;

				if (p->left == x)
				{
					w = p->right;

					if (w != NULL)
					{
						// type 1

						if (w->colour == 'r')
						{
							w->colour = 'b';

							p->colour = 'r';

							LL_Rotation(getRef(root, p->val));

							w = p->right;

						}

						//type 2

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->left != NULL && w->right != NULL)
								{
									if (w->left->colour == 'b' && w->right->colour == 'b')
									{
										w->colour = 'r';

										x = p;

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}

								if (w->left == NULL && w->right == NULL)
								{
									w->colour = 'r';

									x = p;

									if (x == root)
									{
										break;
									}

									p = getParent(root, x->val);
								}


								if (w->left != NULL && w->right == NULL)
								{
									if (w->left->colour == 'b')
									{
										w->colour = 'r';

										x = p;

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}

								if (w->left == NULL && w->right != NULL)
								{
									if (w->right->colour == 'b')
									{
										w->colour = 'r';

										x = p; 

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}
							}
						}


						//type 3

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->left != NULL && w->right != NULL)
								{
									if (w->left->colour == 'r' && w->right->colour == 'b')
									{
										w->left->colour = 'b';

										w->colour = 'r';

										RR_Rotation(getRef(root, w->val));


										w = getRef(root, p->val)->right;


									}
								}

								if (w->left != NULL)
								{
									if (w->left->colour == 'r')
									{
										w->left->colour = 'b';

										w->colour = 'r';

										RR_Rotation(getRef(root, w->val));

										w = getRef(root, p->val)->right;


									}
								}

							}
						}

						//type 4

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->right != NULL)
								{
									if (w->right->colour == 'r')
									{
										w->colour = p->colour;

										p->colour = 'b';

										if (w->right != NULL)
										{
											w->right->colour = 'b';
										}

										LL_Rotation(getRef(root, p->val));

										x = root;

									}
								}

							}
						}

					}

				}

				if (p->right == x)
				{
					w = p->left;

					if (w != NULL)
					{
						// type 1


						if (w->colour == 'r')
						{
							w->colour = 'b';

							p->colour = 'r';

							RR_Rotation(getRef(root, p->val));

							w = p->left;

						}

						//type 2

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->left != NULL && w->right != NULL)
								{
									if (w->left->colour == 'b' && w->right->colour == 'b')
									{
										w->colour = 'r';

										x = p;

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}

								if (w->left == NULL && w->right == NULL)
								{
									w->colour = 'r';

									x = p; 

									if (x == root)
									{
										break;
									}

									p = getParent(root, x->val);
								}


								if (w->left != NULL && w->right == NULL)
								{
									if (w->left->colour == 'b')
									{
										w->colour = 'r';

										x = p; 

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}

								if (w->left == NULL && w->right != NULL)
								{
									if (w->right->colour == 'b')
									{
										w->colour = 'r';

										x = p; 

										if (x == root)
										{
											break;
										}

										p = getParent(root, x->val);
									}
								}
							}
						}

						//type 3

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->left != NULL && w->right != NULL)
								{
									if (w->left->colour == 'b' && w->right->colour == 'r')
									{
										w->right->colour = 'b';

										w->colour = 'r';

										LL_Rotation(getRef(root, w->val));


										w = getRef(root, p->val)->left;


									}
								}

								if (w->right != NULL)
								{
									if (w->right->colour == 'r')
									{
										w->right->colour = 'b';

										w->colour = 'r';

										LL_Rotation(getRef(root, w->val));


										w = getRef(root, p->val)->left;


									}
								}

							}
						}

						//type 4

						if (w != NULL)
						{
							if (w->colour == 'b')
							{
								if (w->left != NULL)
								{
									if (w->left->colour == 'r')
									{
										w->colour = p->colour;

										p->colour = 'b';

										if (w->left != NULL)
										{
											w->left->colour = 'b';
										}

										RR_Rotation(getRef(root, p->val));

										x = root;

									}
								}

							}
						}


					}

				}
			}
		}

		if (x != NULL)
		{
			x->colour = 'b';
		}
		
	}

	void deleteNode(T val, Node<T>* &temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
		
			if (temp->val == val)
			{
				char colorval = '\0';

				Node<T>* x = 0;

				Node<T>* &parentofx = getParent(root, temp->val);
				
				if (temp->left == NULL)
				{
					Node<T>* temp2 = temp;

					x = temp->right;

					temp = temp->right;


					colorval = temp2->colour;			// saved color

					delete temp2;

					if (colorval == 'b')
					{

						deletefix(parentofx, x);

					}

				}

				else if (temp->right == NULL)
				{
					Node<T>* temp2 = temp;

					x = temp->left;

					temp = temp->left;

					colorval = temp2->colour;			// saved color

					delete temp2;

					if (colorval == 'b')
					{
						deletefix(parentofx, x);
					}
 
				}

				else if (temp->left != NULL && temp->right != NULL)
				{
					Node<T>* temp2 = temp->right;

					if (temp2->left != NULL)
					{
						while (temp2->left != NULL)				// get leftmost node in right subtree
						{
							temp2 = temp2->left;
						}

						colorval = temp2->colour;				// save original colour of leftmost

						

						x = temp2->right;						//

						Node<T>* ptemp2 = temp->right;

						while (ptemp2->left != temp2)			// get parent of leftmost node in right subtree
						{
							ptemp2 = ptemp2->left;
						}

						Node<T>* &parentofx2 = getRef(root, ptemp2->val);	//

						ptemp2->left = temp2->right;

						temp->val = temp2->val;

						//if (temp != root)
						//{
						//	//temp->colour = temp2->colour;		//maybe check
						//}

						delete temp2;

						if (colorval == 'b')
						{
							deletefix(parentofx2, x);
						}

					}
					else if (temp2->left == NULL)
					{
						
						
						temp->right = temp2->right;

						temp->val = temp2->val;

						//if (temp != root)
						//{
						//	//temp->colour = temp2->colour;	//maybe check
						//}

						colorval = temp2->colour;

						delete temp2;

						if (colorval == 'b')
						{
							deletefix(getRef(root, temp->val), temp->right);
						}
					}
					
				}			
			}

			else
			{
				if (val < temp->val)
				{
					deleteNode(val, temp->left);
				}

				if (val > temp->val)
				{
					deleteNode(val, temp->right);
				}
			}

		}
	}

	void RangeInOrder(Node<T>*& temp, T min, T max)
	{
		if (temp != NULL)
		{
			RangeInOrder(temp->left, min, max);

			if (temp->val >= min && temp->val <= max)
			{
				cout << temp->val << " ";
			}

			RangeInOrder(temp->right, min, max);
		}
	}

public:

	Tree()
	{
		root = 0;
	}

	void insert(T value)
	{
		
		insertnode(value, root);

	}

	bool search(T value)
	{
		return retrieveval(value, root);
	}

	void InOrderTraversal()
	{
		cout << "Inorder: \t";
		InOrder(root);
		cout << "\n";
	}

	void PreOrderTraversal()
	{
		cout << "Preorder: \t";
		PreOrder(root);
		cout << "\n";
	}

	void PostOrderTraversal()
	{
		cout << "Postorder: \t";
		PostOrder(root);
		cout << "\n";
	}

	void LevelOrder()
	{
		cout << "Level Order: \t";
		BFSearch(root);
		cout << "\n";
	}

	T getMin()
	{
		return findMin(root);

	}

	void deleteval(T val)
	{
		deleteNode(val, root);	
	}

	void rangedsearch(T min, T max)
	{
		cout << "Keys in the given range are: \t";
		RangeInOrder(root, min, max);
		cout << "\n";

	}

	
};

}
