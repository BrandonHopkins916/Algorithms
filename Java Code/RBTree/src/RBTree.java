import java.util.Scanner; 
 
public class RBTree {
	
	private static final boolean RED = true;
    private static final boolean BLACK = false;
    private Node root;
    public int size()    								//Key is to organize the node. Value is data.
    {
       return size(root);
    } 
    private int size(Node h)
    {
       if(h== null)
          return 0;
       else 
          return h.key;
    }
    public boolean isEmpty()
    {
       return root == null;
    }
    private class Node
    {
       private int key; 			//data
       private Node left, right;
       private boolean color;
       private Node(int key, boolean color)
       {
          this.key = key;
          this.color = color;        
       }
     }
 
    public void put(int key)
    {
       root = put(root, key);
       root.color = BLACK;
    }
    private Node put(Node h, int key)
    {
       if (h==null)
          return new Node(key, RED); //creating new node.
       if(key < h.key) 
          h.left = put(h.left, key);
       else if(key > h.key) 
          h.right = put(h.right, key);
       else h.key = key;
    	
       if(isRed(h.right) && !isRed(h.left)) 
          h=rotateLeft(h);
    		
       if(isRed(h.left) && isRed(h.left.left))
          h = rotateRight(h);
    		
       if(isRed(h.left) && isRed(h.right)) 
          flipColors(h);
       return h;
    } 	
    private Node balance(Node h)                 ///In delete it goes thru an infinite loop///
    {
       if(isRed(h.right))
          h = rotateLeft(h);
    
       if(isRed(h.left) && isRed(h.right)) 
          flipColors(h);
    
       if(isRed(h.left) && isRed(h.left.left))
          h = rotateRight(h);
    
       if(isRed(h.right) && !isRed(h.left))
          h = rotateLeft(h);  	 
			 
       return  h;									//balance(h);
    }
    public Node search(int key)
    {
       return search(root, key);
    }
    private Node search(Node h, int key)
    {
       Node curr = root;
       while (curr!=null)
       {
          if(key == curr.key) 
             return curr;
          else if(key < curr.key) 
             curr = curr.left;
          else if(key > curr.key) 
             curr = curr.right;
          else if( key != curr.key)
             System.out.print("Key doesnt exist!! \n");
             return curr;
       }
       return curr;
    }
  
    private boolean isRed(Node h)
    {
       if(h == null)
          return false;
       else
          return h.color == RED ? RED : BLACK;
    }
 	
    private Node rotateLeft(Node h)
    {
       Node x  = h.right;
       h.right = x.left;
       x.left  = h;
       x.color = h.color;
       h.color = RED;
       return x;
    }
    private Node rotateRight(Node h)
    {
       Node x = h.left;
       h.left = x.right;
       x.right = h;
       x.color = h.color;
       h.color = RED;
       return x;
    }
    private void flipColors(Node h)
    {
       h.color = RED;
       h.left.color = BLACK;
       h.right.color = BLACK;
    }
    private Node moveRedLeft(Node h)
    {
       flipColors(h);
       if(isRed(h.right.left))
       {
          h.right = rotateRight(h.right);
          h = rotateLeft(h);
       }
       return h;
    }
    public void deleteMin()
    {
       if(!isRed(root.left) && !isRed(root.right))
          root.color = RED;
       root = deleteMin(root);
       if(!isEmpty()) root.color = BLACK;
    }
    private Node deleteMin(Node h)
    {
       if(h.left == null)
          return null;
       if(!isRed(h.left) && !isRed(h.left.left))
          h = moveRedLeft(h);
       h.left = deleteMin(h.left);
       return balance(h);
    }
 	
    private Node moveRedRight(Node h)
    {
       flipColors(h);
       if(!isRed(h.left.left))
       {
          h = rotateRight(h);
       }
       return h;
    }
 	
    public void deleteMax()
    {
       if(!isRed(root.left) && !isRed(root.right))
          root.color = RED;
       root = deleteMax(root);
       if(!isEmpty()) root.color = BLACK;
    }
 	
    private Node deleteMax(Node h)
    {
       if(isRed(h.left))
          h = rotateRight(h);
       if(h.right == null)
          return null;
       if(!isRed(h.right) && !isRed(h.right.left))
          h = moveRedRight(h);
       h.right = deleteMax(h.right);
       return balance(h);
    }
 	
    public int min(){
       if(isEmpty())
          return 0;
       return min(root).key;
    }
 	 
    private Node min(Node h){
       if(h.left == null)
          return h;
       else
          return min(h.left);
    }
 
public Node delete(int key)
    {
		 if(!isRed(root.left) && !isRed(root.right))
		 {
		   root.color = RED;
		   root = delete(root,key);
		 }
		 
		if(!isEmpty()) 
			root.color = BLACK;	
		return null;
	}
private Node delete(Node h, int key)
    {
       if(key < h.key)
			{
			 if(!isRed(h.left) && !isRed(h.left.left))
			   h = moveRedLeft(h);
			 h.left = delete(h.left,key);
			}
			else
			{
			 if(isRed(h.left))
			  h = rotateRight(h);
			 if(key == h.key  && (h.right == null))
			  return null;
			 if(!isRed(h.right) && !isRed(h.right.left))
			   h = moveRedRight(h);
			 if(key == h.key)
			 {
			  h.key = min(h.right).key;
			  h.right = deleteMin(h.right);
			 }
			 else h.right = delete(h.right,key);
			 }
			 return balance(h);
			}
   
	public void postOrder(Node h)                     // inorder print
    { 
       if(h != null)
       {
          postOrder(h.left);
          postOrder(h.right);
          System.out.println(h.key + " " + h.color); //1, 3, 2 ,(red) 5, 4
       }
    }
	public static void main(String[] args) {
        RBTree t  = new RBTree();
        Scanner s = new Scanner(System.in);
        int key;
        int[] a = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
        for(int i = 0; i < a.length; i++)
        {
           t.put(a[i]);
           System.out.print(a[i] + " ");
        }
        System.out.println("");
        System.out.print("Post Order: \n");
        t.postOrder(t.root);
        System.out.println("");
      
       
        System.out.println("What numbers do you want to search");
        int f = s.nextInt();
        System.out.println(t.search(f).key);
        System.out.println("What number are you deleting");  /// Delete value
        int d = s.nextInt();
        System.out.println(t.delete(d).key);
        t.postOrder(t.root);  

	}

}
