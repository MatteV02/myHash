#include "FileHash.h"

#include <fstream>

#include "ShowHash.h"
#include "qfiledialog.h"
#include "qmessagebox.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <cryptlib.h>
#include <sha.h>
#include <md5.h>
#include <hex.h>
#include <files.h>

using namespace CryptoPP;
using namespace std;

FileHash::FileHash(QWidget* parent)
	: QWidget(parent), alg((Algorithms)0)
{
	ui.setupUi(this);
}

FileHash::~FileHash()
{}

void FileHash::SetAlgorithm(Algorithms type)
{
	alg = type;
}

void FileHash::OpenFileDlg()
{
	const QString filename = QFileDialog::getOpenFileName(this, tr("Choose a file..."));

	ui.filePath->setText(filename);
}

void FileHash::Hash()
{
	const string filename = ui.filePath->text().toLatin1().data();

	ifstream file(filename, ios::binary);

	if (!file.is_open())
	{
		QMessageBox message;
		message.setText(tr("ERROR, file not found."));
		message.setInformativeText(tr("Retry."));
		message.setStandardButtons(QMessageBox::Ok);
		message.setDefaultButton(QMessageBox::Ok);

		message.exec();

		return;
	}

	string output;

	SHA1 hashSHA1;
	SHA256 hashSHA256;
	SHA512 hashSHA512;
	Weak::MD5 hashMD5;

	switch (alg)
	{
	case SHA1_e:
		FileSource(file, true, new HashFilter(hashSHA1, new HexEncoder(new StringSink(output))));
		break;
	case SHA256_e:
		FileSource(file, true, new HashFilter(hashSHA256, new HexEncoder(new StringSink(output))));
		break;
	case SHA512_e:
		FileSource(file, true, new HashFilter(hashSHA512, new HexEncoder(new StringSink(output))));
		break;
	case MD5_e:
		FileSource(file, true, new HashFilter(hashMD5, new HexEncoder(new StringSink(output))));
		break;
	default:
		break;
	}

	ShowHash dialog(output, this);

	dialog.exec();

}