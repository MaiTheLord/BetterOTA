/*
    AUTO GENERATED CODE - DON'T EDIT BY HAND
*/

#ifndef SCRIPT_H
#define SCRIPT_H

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

#endif //SCRIPT_H
