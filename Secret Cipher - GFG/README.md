# Secret Cipher
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Geek wants to send an&nbsp;encrypted message in the form of string <strong>S</strong>&nbsp;to his friend Keeg&nbsp;along with instructions on how to decipher the message.&nbsp;To decipher the message, his friend&nbsp;needs to iterate over the message string from left to right, if he finds a <strong>'*'</strong>, he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the <strong>'*'</strong>.<br>
Can you help Geek encrypt his message string <strong>S</strong>?&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Note:</strong> If the string can be encrypted in multiple ways, find&nbsp;the smallest encrypted string.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> S = "ababcababcd"
<strong>Output:</strong> ab*c*d
<strong>Explanation: </strong>We can encrypt the string 
in following way : "ababcababcd"&nbsp;-&gt; 
"ababc*d" -&gt; "ab*c*d"</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>S = "zzzzzzz"
<strong>Output:</strong> z*z*z
<strong>Explanation: </strong>The string can be encrypted 
in 2 ways: "z*z*z" and "z**zzz". Out of 
the two "z*z*z" is smaller in length.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>secretCipher()</strong> which takes the message string <strong>S</strong> as input parameter and returns the shortest possible encrypted&nbsp;string.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:&nbsp;</strong><br>
1 ≤ |S| ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>