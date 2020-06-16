/*
1371. 每个元音包含偶数次的最长子字符串
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：
每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

示例 1：

输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2：

输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
示例 3：

输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
 

提示：

1 <= s.length <= 5 x 10^5
s 只包含小写英文字母。

来源：LeetCode
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/
class Solution {
public:
    //状态压缩 + 哈希表
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> stateToIndex;
        int state = 0x0;
        //初始化，刚开始时，state的状态已经是0x00000，已经出现，因此必须记录
        //刚开始的时候 aeiou都是出现了0次，偶次数
        stateToIndex[state] = -1;
        
        //aeiou分别在第12345个bit，来表示出现次数的奇偶性
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'a')
                state ^= 0x00001;
            if(s[i] == 'e')
                state ^= 0x00010;
            if(s[i] == 'i')
                state ^= 0x00100;
            if(s[i] == 'o')
                state ^= 0x01000;
            if(s[i] == 'u')
                state ^= 0x10000;
            if(stateToIndex.count(state))
                res = max(res, i - stateToIndex[state]);
            else
                stateToIndex[state] = i;
        }
        
        return res;
    }
};

// aeiou每个元音用一个bit一共5个bit，32种奇偶次数组合状态，比如10101可以表示aiu出现奇数次数
// oe则出现偶数次数，每当遍历一个字符，就可以改变当前的aeiou出现的奇偶次数，也即是改变状态
// 显然，如果两次出现了同样的状态，假设第一次出现在i处
// 第二次出现在j处，那么i+1-j之间的字符串肯定是满足aeiou出现均为偶数次数的
// 因为只有经历了偶数个aeiou，才能回到之前的状态，为了使得合理的字符串最长
// 那么第一次出现此状态时，就需要记录到下标，然后下次遇到相同状态，计算最大长度
/*
首先题目中要求子字符串中每个元音字母恰好出现偶数次，我们就可以使用 0 和 1 来标识每个字母的状态(偶数次或奇数次)，我们不需要知道每个字母出现的完整次数，只需要知道这个次数的奇偶性
那么我们可以注意到奇数次 + 1 = 偶数次，偶数次 + 1 = 奇数次，所以我们可以使用 异或 来参与运算： 比如 aba
初始时 status = 00000，然后到 a 的时候 00000 ^ 00001 = 00001，1 说明 a 出现奇数次
然后到 b 的时候 00001 ^ 00010 = 00011，两个 1 说明 a、b 都出现奇数次
最后到 a 的时候 00011 ^ 00001 = 00010，说明只有 b 出现奇数次了。
以上也说明我们确实是可以使用状态码去标识每个元音字母出现次数的奇偶性。
那么我们怎么去统计最长子串的长度呢？
首先我们先盘盘哪些子串符合要求，因为现在每个下标对应的状态码其实也就只有 0 和 1
如果坐标 i 对应的状态码是 00011，坐标 j 对应的状态码是 00011，那么他们俩中间的元音字母数一定是偶数，如果某一位不相同，那么绝对不可能是偶数，因为偶数-奇数=奇数，奇数-偶数=奇数
*/