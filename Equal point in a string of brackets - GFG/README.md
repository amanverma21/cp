# Equal point in a string of brackets
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>S</strong> of opening and closing brackets '(' and ')' only. The task is to find an equal point. An&nbsp;<strong>equal point</strong>&nbsp;is an index such that the number of closing brackets on right from that point must be equal to number of opening brackets before that point.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str = "(())))("
<strong>Output: </strong>4
<strong>Explanation:</strong>
After index 4, string splits into (())
and ))(. Number of opening brackets in the
first part is equal to number of closing
brackets in the second part.</span>
</pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input :</strong> str = "))"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
As after 2nd position i.e. )) and "empty"
string will be split into these two parts:
So, in this number of opening brackets i.e.
0 in the first part is equal to number of
closing brackets in the second part i.e.
also 0.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>findIndex()</strong>&nbsp;which takes the string <strong>S</strong><strong> </strong>as inputs and returns the occurrence of the equal point in the string.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ S ≤ 10<sup>6</sup><br>
String can be unbalanced</span></p>
</div>