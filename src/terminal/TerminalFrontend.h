/*
    AUTO GENERATED CODE - DON'T EDIT BY HAND
*/

#ifndef TERMINAL_FRONTEND_H
#define TERMINAL_FRONTEND_H

const char* INDEX_HTML = R"(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8"/>
    <title>Terminal</title>
    <link rel="stylesheet" href="style.css"/>
</head>

<body>
<div id="wrapper">
    <div id="title">
        <p>Terminal</p>
        <p id="disconnected_message">disconnected</p>
    </div>
    <div id="log"></div>

    <div id="message_line">
        <input id="message_input" name="msg" type="text" autocapitalize="off"/>
        <button id="send_button">send</button>
    </div>
</div>

<script src="script.js"></script>
</body>

</html>
)";

const char* STYLE_CSS = R"(
body {
    margin: 2vw 2vw 0 2vw;
}

#wrapper {
    background: #efefef;
    border: 2px solid #000000;
    height: calc(100vh - 4vw);
    display: flex;
    flex-direction: column;
}

#title {
    padding: 0 25px;
    display: flex;
    flex-direction: row;
    justify-content: space-between
}

#disconnected_message {
    color: #ff0000;
}

#log {
    text-align: left;
    margin: 0 25px auto;
    padding: 10px;
    background: #ffffff;
    border: 1px solid #000000;
    overflow: auto;
    white-space: pre-line;
    flex: 1;
}

#message_line {
    padding: 15px 25px;
    display: flex;
    gap: 10px;
    justify-content: center;
}

#message_input {
    flex: 1;
    border: 1px solid #000000;
    padding: 6px 15px
}

#send_button {
    background: #424242;
    border: 1px solid #000000;
    color: white;
    padding: 4px 10px;
}
)";

const char* SCRIPT_JS = R"(
const messageInput = document.getElementById('message_input');

function send() {
    if (messageInput.value === "") return;
    fetch("/send", {
        method: "POST",
        headers: { "Content-Type": "text/strings" },
        body: messageInput.value
    }).then(response => { if (response.ok) hideDisconnectedMessage(); }).catch(showDisconnectedMessage);
    messageInput.value = "";
}

messageInput.addEventListener("keyup", (event) => {
  if (event.key === 'Enter') {
    event.preventDefault();
    send();
  }
});

document.getElementById("send_button").onclick = send;


setInterval(() => {
    fetch("/fetch").then(response => {
        if (!response.ok) return;
        hideDisconnectedMessage();
        if (response.status === 200) response.text().then(text => {
            const log = document.getElementById("log");
            const shouldScroll = (log.scrollHeight - log.scrollTop - log.clientHeight < 1);
            log.innerHTML += text;
            if (shouldScroll) log.scrollTop = log.scrollHeight;
        });
    }).catch(showDisconnectedMessage);
}, 500);


function showDisconnectedMessage() {
    document.getElementById("disconnected_message").style.display = "block";
}

function hideDisconnectedMessage() {
    document.getElementById("disconnected_message").style.display = "none";
}
)";

#endif //TERMINAL_FRONTEND_H
