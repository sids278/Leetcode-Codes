class Solution {
public:
    void dfs(string word, vector<vector<string>> &ans, vector<string> &seq, string &startword, int &wsize, map<string, int> &wordmap)
    {
        //?push the word into the sequence.
        seq.push_back(word);

        if (word == startword)
        {

            reverse(seq.begin(), seq.end());
            //*since we are pushing elements from last to first word, ie. in a reverse manner.
            //* Why am i pushing it in reverse manner? Explaination at the last line of this solution

            ans.push_back(seq); //*pushing this sequence into our row of answer vector.

            reverse(seq.begin(), seq.end()); //*before returning just reverse the sequence vector again (as it is passed by reference)

            seq.pop_back();
            //* remeber this as "Pop 1.0"
            //* the path to this word is covered hence remove the pushed word since we no longer need it in our sequence.

            return;
        }

        int lvl = wordmap[word]; //*storing the current level of the word.

        for (int i = 0; i < wsize; i++) //* runs for the size of beginWord, so that character at each index is replaced one by one.
        {
            char org = word[i]; //* storing the original character of word.at(i);

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch; //* Changing the character that is generate through our inner for loop.

                if (wordmap.find(word) != wordmap.end() && wordmap[word] + 1 == lvl)
                //* check if that word exist in our wordmap meaning we can use that word then
                //* check if the level is just 1 less than our current level or current level = 1 + lvl_of_foundword
                {
                    dfs(word, ans, seq, startword, wsize, wordmap); //*calling dfs again for the found word.
                }
            }

            word[i] = org; //*replacing the modified character by the original character.
        }

        //*since we already covered the path for current word , removing it from our sequence vector
        //* this makes sure that we dont use this same word again in some other path.
        //* Example : path1 = {cog,log,loz} , path2 = {cog,coz,loz} (added in reverse manner , meaning loz is the starting word here)
        //* so the loz word will be already removed in POP 1.0 above , which means we are left with log/coz.
        //* this log/coz will be popped here so the path isnt something like {cog,log,coz,loz}
        //* (if it's confusing you just remeber we are pushing words in the sequence vector , so during backtracking we need to pop it else it remains in the sequence vector.)
        seq.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        //? To store the answer
        vector<vector<string>> ans;

        //? Creation of an unordered set ( reason : O(1) amortized time complexity) to store all words.
        unordered_set<string> wordset(wordList.begin(), wordList.end());

        //* if the endword isnt in the set , no possible path to reach it hence return empty vector.
        if (wordset.find(endWord) == wordset.end())
            return ans;

        //? Storing of words and their respective levels.
        map<string, int> wordmap;
        queue<string> q;

        q.push(beginWord);

        //? Erasing the beginword from the set (if it is present in the set)
        wordset.erase(beginWord);

        //? Inserting beginword , current level is 1 you can take any integer thought.
        wordmap.insert({beginWord, 1});

        int size = beginWord.size();

        while (!q.empty())
        {
            string word = q.front();

            if (word == endWord) //* if at any point we find the enqword in the queue , break the while loop.
                break;

            int lvl = wordmap[word]; //* Storing current level of the word.

            q.pop();

            for (int i = 0; i < size; i++)
            {
                char org = word[i]; //*storing original character at ith index

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (wordset.find(word) != wordset.end()) //* if the modified word is in the wordset.
                    {
                        q.push(word);

                        //?Erasing/Removing it from the set ensuring that it isnt used again / pushed again into the queue.
                        wordset.erase(word);

                        //? Adding the word in our queue along with the level
                        //? which is level of the initial word we got from the queue and it is one level ahead hence lvl+1.
                        wordmap.insert({word, lvl + 1});
                    }
                }

                word[i] = org; //* replacement of modified character at ith index with original character.
            }
        }

        //? if endword isnt in the map , it means we were unable to form any path which leads us to the endword, hence directly returning ans (empty vector)
        //? And if the endword is present in the map , calling dfs to store the paths.
        if (wordmap.find(endWord) != wordmap.end())
        {
            vector<string> seq; //* this vector stores the sequence.
            dfs(endWord, ans, seq, beginWord, size, wordmap);
        }

        return ans;
    }
};