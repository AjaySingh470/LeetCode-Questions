<h2><a href="https://leetcode.com/problems/special-array-ii/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #679cca;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3152. Special Array II</a></h2><h3>Medium</h3><hr><div><p>An array is considered <strong>special</strong> if every pair of its adjacent elements contains two numbers with different parity.</p>

<p>You are given an array of integer <code>nums</code> and a 2D integer matrix <code>queries</code>, where for <code>queries[i] = [from<sub>i</sub>, to<sub>i</sub>]</code> your task is to check that <span data-keyword="subarray">subarray</span> <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> is <strong>special</strong> or not.</p>

<p>Return an array of booleans <code>answer</code> such that <code>answer[i]</code> is <code>true</code> if <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> is special.<!-- notionvc: e5d6f4e2-d20a-4fbd-9c7f-22fbe52ef730 --></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,4,1,2,6], queries = [[0,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[false]</span></p>

<p><strong>Explanation:</strong></p>

<p>The subarray is <code>[3,4,1,2,6]</code>. 2 and 6 are both even.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,1,6], queries = [[0,2],[2,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[false,true]</span></p>

<p><strong>Explanation:</strong></p>

<ol>
	<li>The subarray is <code>[4,3,1]</code>. 3 and 1 are both odd. So the answer to this query is <code>false</code>.</li>
	<li>The subarray is <code>[1,6]</code>. There is only one pair: <code>(1,6)</code> and it contains numbers with different parity. So the answer to this query is <code>true</code>.</li>
</ol>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;= nums.length - 1</code></li>
</ul>
</div>