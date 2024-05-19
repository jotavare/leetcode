class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        int stringSize = s.length();
        bool counting = false;

        for (int i = stringSize - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                count++;
                counting = true;
            }
            else if (counting)
            {
                break;
            }
        }

        return count;
    }
};
