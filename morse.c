#include <stdio.h>
#include <string.h>

const char* decode(char *cipher, char *alphabet);

int main(int argc, char const *argv[])
{
	char alphabet[] = "**ETIANMSURWDKGOHVF?L?PJBXCYZQ??54?3?*?2*?+*???16=/*?*?*7*??8*90************?_****\"**.****@***\'**-********;!()*****,****:*******";
	char cipher[] = ".- -...";
    printf("Kod:\n%s\n", cipher);
	const char *text;
	text = decode(cipher, alphabet);
	printf("\nTekst: %s", text);
	getchar();
    return 0;
}

const char* decode(char *cipher, char *alphabet) {
	static char text[100] = {};
	char *ch;
	int count_ch = 0, count_t = 0, character = 1, i;
	ch = strtok(cipher, " ");
	while (ch != NULL) {
		count_ch = 0;
		count_ch = strlen(ch);
		for (i = 0; i < count_ch; ++i) {
			if (ch[i] == '.') {
				character *= 2;
			}
			else if (ch[i] == '-') {
				character *=2;
				character +=1;
			}
		}
		if (character > strlen(alphabet)) {
			character = 0;
		}
		text[count_t] = alphabet[character];
		ch = strtok(NULL, " ");
		character = 1;
		++count_t;
	}
	return text;
}
