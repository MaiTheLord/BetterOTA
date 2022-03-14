TEMPLATE =
'/*
    AUTO GENERATED CODE - DON\'T EDIT BY HAND
*/

#ifndef TERMINAL_FRONTEND_H
#define TERMINAL_FRONTEND_H

const char* INDEX_HTML = R"(
%s)";

const char* STYLE_CSS = R"(
%s)";

const char* SCRIPT_JS = R"(
%s)";

#endif //TERMINAL_FRONTEND_H
'

File.open("../TerminalFrontend.h", 'w') do |f|
    f.write(TEMPLATE % [File.read("index.html"), File.read("style.css"), File.read("script.js")])
end
