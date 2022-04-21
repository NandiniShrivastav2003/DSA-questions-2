import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
//Node class structure of a tree
class Node{
    int data;
    Node left;
    Node right;
    Node(int val){
        this.data=val;
        left=null;
        right=null;
    }
}
//insertion in a binary tree
 class Tree_insertion {
    public static void insert(Node root,int x) {
        if (root == null) {
            root = new Node(x);
            return;
        }
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while (!q.isEmpty()) {
            Node front = q.poll();
            if (front.left == null) {
                front.left = new Node(x);
                break;
            } else {
                q.add(front.left);
            }
            if (front.right == null) {
                front.right = new Node(x);
                break;
            } else {
                q.add(front.right);
            }
        }
    }
    //post-order traversal of a tree
    public static  void traversal(Node root){
        if(root == null){return;}
        traversal(root.left);
        traversal(root.right);
        System.out.print(root.data+" ");
    }
    //deletion in a binary tree
    public Node deletionBT(Node root, int key){


        Node temp=null;
        Node to_delete=null;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            temp=q.poll();
            if(temp.data == key){
                to_delete=temp;

            }
            if(temp.left != null){q.add(temp.left);}
            if(temp.right != null){q.add(temp.right);}
        }

        if(root == null){return root;}


        q = new LinkedList<>();
        q.add(root);

        Node cn;
        while(!q.isEmpty())
        {
            cn = q.poll();

            if(cn.left != null){
                if(cn.left == temp){
                    cn.left = null;
                } else
                    q.add(cn.left);
            }

            if(cn.right != null){
                if(cn.right == temp){
                    cn.right = null;
                } else
                    q.add(cn.right);
            }


            to_delete.data=temp.data;
        }

        return root;
    }

    public static void main(String[] args) {
Node root=new Node(10);
insert(root,20);
insert(root,30);
insert(root,7);
insert(root,15);
insert(root,8);
//traversal(root);

Tree_insertion obj=new Tree_insertion();
Node p=obj.deletionBT(root,20);
       // System.out.println(p.data);
traversal(p);
    }
}
