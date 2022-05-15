/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Codec
{
    public string serialize(TreeNode root)
    {
        IList<int> list = new List<int>();
        PostOrder(root, list);
        return string.Join(",", list);
    }

    public TreeNode deserialize(string data)
    {
        if (data.Length == 0)
        {
            return null;
        }
        string[] arr = data.Split(",");
        Stack<int> stack = new Stack<int>();
        int length = arr.Length;
        for (int i = 0; i < length; i++)
        {
            stack.Push(int.Parse(arr[i]));
        }
        return Construct(int.MinValue, int.MaxValue, stack);
    }

    private void PostOrder(TreeNode root, IList<int> list)
    {
        if (root == null)
        {
            return;
        }
        PostOrder(root.left, list);
        PostOrder(root.right, list);
        list.Add(root.val);
    }

    private TreeNode Construct(int lower, int upper, Stack<int> stack)
    {
        if (stack.Count == 0 || stack.Peek() < lower || stack.Peek() > upper)
        {
            return null;
        }
        int val = stack.Pop();
        TreeNode root = new TreeNode(val);
        root.right = Construct(val, upper, stack);
        root.left = Construct(lower, val, stack);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;