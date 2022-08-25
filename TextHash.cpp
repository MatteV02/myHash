#include "TextHash.h"
#include "ShowHash.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptlib.h>
#include <sha.h>
#include <md5.h>
#include <hex.h>

#include <string>

using namespace CryptoPP;
using namespace std;

TextHash::TextHash(QWidget *parent)
	: QWidget(parent), alg((Algorithms)0)
{
	ui.setupUi(this);

}

TextHash::~TextHash()
{}

void TextHash::SetAlgorithm(Algorithms type)
{
	alg = type;
}

void TextHash::Hash()
{
	const string inputText = ui.textEdit->toPlainText().toLatin1().data();

	string output;

	SHA1 hashSHA1;
	SHA256 hashSHA256;
	SHA512 hashSHA512;
	Weak::MD5 hashMD5;

	switch (alg)
	{
	case SHA1_e:
		StringSource(inputText, true, new HashFilter(hashSHA1, new HexEncoder(new StringSink(output))));
		break;
	case SHA256_e:
		StringSource(inputText, true, new HashFilter(hashSHA256, new HexEncoder(new StringSink(output))));
		break;
	case SHA512_e:
		StringSource(inputText, true, new HashFilter(hashSHA512, new HexEncoder(new StringSink(output))));
		break;
	case MD5_e:
		StringSource(inputText, true, new HashFilter(hashMD5, new HexEncoder(new StringSink(output))));
		break;
	default:
		break;
	}

	ShowHash dialog(output, this);

	dialog.exec();
}
