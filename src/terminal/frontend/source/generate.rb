TEMPLATE =
'/*
    AUTO GENERATED CODE - DON\'T EDIT BY HAND
*/

#ifndef %s
#define %s

const char* %s = R"(
%s)";

#endif //%s
'

def generate_file(source, target, include_guard, const_name)
  File.open("../" + target, 'w') do |f|
    f.write(TEMPLATE % [include_guard, include_guard, const_name, File.read(source), include_guard])
  end
end

generate_file("index.html", "index.h", "INDEX_H", "INDEX_HTML")
generate_file("style.css", "style.h", "STYLE_H", "STYLE_CSS")
generate_file("script.js", "script.h", "SCRIPT_H", "SCRIPT_JS")
