#ifndef STR_FORMAT_H
#define STR_FORMAT_H

#include <Arduino.h>

#define FORMAT_AFFIXES {"%s", "%d"}

class StrClass {
private:
    StrClass() = default;

    inline static int getAffixIndex(const String& base) {
        int index = -1;

        for (const String& affix : FORMAT_AFFIXES) {
            int currentIndex = base.indexOf(affix);
            if (currentIndex > -1 && (currentIndex < index || index == -1)) index = currentIndex;
        }

        return index;
    }

    template <typename T>
    inline static String formatOne(const String& base, T p1, int affixIndex) {
        String left = base.substring(0, affixIndex);
        String right = base.substring(affixIndex + 2, base.length());
        return left + String(p1) + right;
    }

public:
    static StrClass getInstance();

    template<typename T>
    String format(const String& base, T p1) {
        int affixIndex = getAffixIndex(base);

        if (affixIndex == -1) return base;
        else return formatOne(base, p1, affixIndex);
    }

    template<typename T, typename... T2>
    String format(const String& base, T p1, T2... p2) {
        int affixIndex = getAffixIndex(base);

        if (affixIndex == -1) return base;
        else return format(formatOne(base, p1, affixIndex), p2...);
    }
};

#endif //STR_FORMAT_H
