public class Solution
{
    public int CountVowelStrings(int n)
    {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
}