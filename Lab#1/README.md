  <div id="readme" class="blob instapaper_body">
    <article class="markdown-body entry-content" itemprop="mainContentOfPage"><h1>
<a name="laboratory-1-login-application" class="anchor" href="#laboratory-1-login-application"><span class="octicon octicon-link"></span></a>Laboratory #1: Login Application</h1>

<h4>
<a name="application-done-in-c-using-gtk-with-gtkmm-interface-in-codeblocks" class="anchor" href="#application-done-in-c-using-gtk-with-gtkmm-interface-in-codeblocks"><span class="octicon octicon-link"></span></a>Application done in C++ using GTK+ with gtkmm interface in CodeBlocks</h4>

<h2>
<a name="i-have-completed-the-following-objectives" class="anchor" href="#i-have-completed-the-following-objectives"><span class="octicon octicon-link"></span></a>I have completed the following Objectives:</h2>

<ul>
<li><b>Created a Windowed application in Ubuntu</b></li>
<li>
<b>Added 2 buttons to window</b> </li>
<li>
<b>Added 2 text inputs to window: </b> 

<ul>
<li>default styles</li>
<li>colored labels</li>
<li>bold labels</li>
</ul>
</li>
<li>
<b>Added 2 text elements to window:</b> 
<ul>
<li>default styles</li>
<li>added hint(markup)</li>
<li>modified text imput type (password)</li>
</ul>
</li>
<li>
<b>Made elements to interact or change other elements</b>

<ul>
<li>change username and password labels to red when credentials are wrong</li>
<li>reset text imputs when credentials are correct</li>
</ul>
</li>
<li>
<b>Changed behavior of different window actions</b>

<ul>
<li>negative exit confirmation brings up a dialog with modified size</li>
<li>hide the exit confirmation dialog when no is pressed</li>
</ul>
</li>
</ul><h3>
<a name="login-page" class="anchor" href="#login-page"><span class="octicon octicon-link"></span></a>Login Page</h3>

<p><a href="https://github-camo.global.ssl.fastly.net/659cb45eaa8e6e32d6f96969785edbd519d0887c/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323625334132342e706e67" target="_blank"><img src="https://github-camo.global.ssl.fastly.net/659cb45eaa8e6e32d6f96969785edbd519d0887c/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323625334132342e706e67" alt="alt text" title="Main Login Window" data-canonical-src="https://dl.dropboxusercontent.com/u/104573566/Screenshot%20from%202014-02-16%2020%3A26%3A24.png" style="max-width:100%;"></a></p>

<h3>
<a name="when-user-inputs-wrong-credentials" class="anchor" href="#when-user-inputs-wrong-credentials"><span class="octicon octicon-link"></span></a>When user inputs wrong credentials</h3>

<p><a href="https://github-camo.global.ssl.fastly.net/f56f02fd3ff827da94df45b20ab83ebff9b56d2e/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341343025334135302e706e67" target="_blank"><img src="https://github-camo.global.ssl.fastly.net/f56f02fd3ff827da94df45b20ab83ebff9b56d2e/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341343025334135302e706e67" alt="alt text" title="Wrong Credentials" data-canonical-src="https://dl.dropboxusercontent.com/u/104573566/Screenshot%20from%202014-02-16%2020%3A40%3A50.png" style="max-width:100%;"></a></p>

<h3>
<a name="correct-username-and-password" class="anchor" href="#correct-username-and-password"><span class="octicon octicon-link"></span></a>Correct username and password</h3>

<p><a href="https://github-camo.global.ssl.fastly.net/9bc62bfe0e8a8631081bf3e7bee5b7f72a9e4e96/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323725334134362e706e67" target="_blank"><img src="https://github-camo.global.ssl.fastly.net/9bc62bfe0e8a8631081bf3e7bee5b7f72a9e4e96/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323725334134362e706e67" alt="alt text" title="Login Successfully" data-canonical-src="https://dl.dropboxusercontent.com/u/104573566/Screenshot%20from%202014-02-16%2020%3A27%3A46.png" style="max-width:100%;"></a></p>

<h3>
<a name="on-quit-button-clicked" class="anchor" href="#on-quit-button-clicked"><span class="octicon octicon-link"></span></a>On Quit Button Clicked</h3>

<h4>
<a name="if-the-user-confirms-the-app-will-terminate" class="anchor" href="#if-the-user-confirms-the-app-will-terminate"><span class="octicon octicon-link"></span></a>if the user confirms the app will terminate</h4>

<p><a href="https://github-camo.global.ssl.fastly.net/8f720e74570f2ea2c25fd1fd2232b784e68d973a/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323725334135392e706e67" target="_blank"><img src="https://github-camo.global.ssl.fastly.net/8f720e74570f2ea2c25fd1fd2232b784e68d973a/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323725334135392e706e67" alt="alt text" title="Quit Confirmation" data-canonical-src="https://dl.dropboxusercontent.com/u/104573566/Screenshot%20from%202014-02-16%2020%3A27%3A59.png" style="max-width:100%;"></a></p>

<h4>
<a name="but-if-the-user-will-click-no" class="anchor" href="#but-if-the-user-will-click-no"><span class="octicon octicon-link"></span></a>but if the user will click "No"</h4>

<p><a href="https://github-camo.global.ssl.fastly.net/fc263c490509a5dad805f888264ac7a166f37a09/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323825334131332e706e67" target="_blank"><img src="https://github-camo.global.ssl.fastly.net/fc263c490509a5dad805f888264ac7a166f37a09/68747470733a2f2f646c2e64726f70626f7875736572636f6e74656e742e636f6d2f752f3130343537333536362f53637265656e73686f7425323066726f6d253230323031342d30322d31362532303230253341323825334131332e706e67" alt="alt text" title="No Clicked" data-canonical-src="https://dl.dropboxusercontent.com/u/104573566/Screenshot%20from%202014-02-16%2020%3A28%3A13.png" style="max-width:100%;"></a></p>


### Conclusion
In this laboratory work I familiarized myself with basics of programming windowed applications. I created a simple application in C++ with the help of GTK, also some custom elements inside main window like buttons, labels and text inputs. Besides these custom dialogs are present. All these elements were implemented programatically, so that i understand better how everything works from the inside. 

For me most parts were straightforward, as gtkmm has a very useful and complete documentation together with examples;  besides this I informed myself well enough to be able to start working on this laboratory work.
#### Difficulties
  * adding custom background to the main window.
  * override close and minimize default buttons
  * as far as i understood, gtkmm does not let custom styles for buttons to be written programatically. There are two not very elegant workarounds for this:
    1. Create label, set it's background as button, and implement a signal_click (visually it would look and act like a button) 
    2. Import custom styles from a CSS file which will contain all button's properties 

    


<h4>
<a name="bibliography" class="anchor" href="#bibliography"><span class="octicon octicon-link"></span></a>Bibliography</h4>

<ul>
<li><a href="https://developer.gnome.org/gtkmm-tutorial/unstable/">https://developer.gnome.org/gtkmm-tutorial/unstable/</a></li>
<li><a href="http://stackoverflow.com/">http://stackoverflow.com/</a></li>
<li><a href="http://blog.mpshouse.com/">http://blog.mpshouse.com/</a></li>
</ul><h3>


<h4>
<a name="Compiling" class="anchor" href="#compiling"><span class="octicon octicon-link"></span></a>Compiling The Project</h4>
<p>The Program can be compiled by executing the following commands in terminal: &nbsp; </p>


    g++ mywindow.cpp mywindow.h main.cpp -o lab1 `pkg-config gtkmm-3.0 --cflags --libs`
    ./lab1 





----------------------------------------------  End Of File -----------------------------------------------

<a name="legal-compliance" class="anchor" href="#legal-compliance"><span class="octicon octicon-link"></span></a>Legal compliance</h3>
<p>Copyright (c) 2014, LuchFilip
All rights reserved.</p>

<p>Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:</p>

<p>Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
Neither the name of the Raspberry Pi Foundation nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</p></article>
  </div>

  </div>
</div>
