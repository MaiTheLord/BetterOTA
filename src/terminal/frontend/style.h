/*
    AUTO GENERATED CODE - DON'T EDIT BY HAND
*/

#ifndef STYLE_H
#define STYLE_H

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

#endif //STYLE_H
