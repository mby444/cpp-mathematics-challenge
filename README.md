# cpp-mathematics-challenge

Find which math expression matches the answer that you are given, if you have an integer answer, and a list of math expressions.



<b>Task:</b> 

Test each math expression to find the first one that matches the answer that you are given.



<b>Input Format:</b> 

Two inputs: an integer and a space separated string of math expressions. The following operations need to be supported: addition +, subtraction -, multiplication *, division /. 

An expression can include multiple operations.



<b>Output Format:</b> 

A string that tells the index of the first math expression that matches. If there are no matches, output 'none'.



<b>Sample Input:</b> 
```sh
15
(2+100) (5*3) (14+1)
```


<b>Sample Output:</b> 
```sh
index 1
```


<b>Explanation:</b> 

Index counting starts at 0, so '(5*3)' is at index 1 and matches your answer of 15.
