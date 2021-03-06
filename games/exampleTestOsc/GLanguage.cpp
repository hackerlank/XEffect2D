#include "GLanguage.h"
#include "XXml.h"
using namespace XE;
XBool GLanguage::loadFromFile(const std::string &filename)	//从文件中读取字符串
{//下面从字符串中读取相关的字符串
	TiXmlDocument doc;
	if(!doc.LoadFile(filename)) return XFalse;
	TiXmlNode *rootNode = doc.FirstChild("root");
	if(rootNode == NULL) return XFalse;
	XXml::getXmlAsString(rootNode,"tabTitileStr",m_tabTitileStr);
	XXml::getXmlAsString(rootNode,"openBtnOpenStr",m_openBtnOpenStr);
	XXml::getXmlAsString(rootNode,"openBtnCloseStr",m_openBtnCloseStr);
	XXml::getXmlAsString(rootNode,"addKMBtnStr",m_addKMBtnStr);
	XXml::getXmlAsString(rootNode,"delKMBtnStr",m_delKMBtnStr);
	XXml::getXmlAsString(rootNode,"clearKMBtnStr",m_clearKMBtnStr);
	XXml::getXmlAsString(rootNode,"modifyKMBtnStr",m_modifyKMBtnStr);
	XXml::getXmlAsString(rootNode,"oscDataTxtStr",m_oscDataTxtStr);
	XXml::getXmlAsString(rootNode,"oscTypeStr",m_oscTypeStr);
	XXml::getXmlAsString(rootNode,"oscAddressStr",m_oscAddressStr);
	XXml::getXmlAsString(rootNode,"addBtnStr",m_addBtnStr);
	XXml::getXmlAsString(rootNode,"delBtnStr",m_delBtnStr);
	XXml::getXmlAsString(rootNode,"clearBtnStr",m_clearBtnStr);
	XXml::getXmlAsString(rootNode,"modifyBtnStr",m_modifyBtnStr);
	XXml::getXmlAsString(rootNode,"textDataStr",m_textDataStr);
	XXml::getXmlAsString(rootNode,"textTypeStr",m_textTypeStr);
	XXml::getXmlAsString(rootNode,"textAddressStr",m_textAddressStr);
	XXml::getXmlAsString(rootNode,"textTimesStr",m_textTimesStr);
	XXml::getXmlAsString(rootNode,"textSpacingStr",m_textSpacingStr);
	XXml::getXmlAsString(rootNode,"sendBtnOpenStr",m_sendBtnOpenStr);
	XXml::getXmlAsString(rootNode,"sendBtnCloseStr",m_sendBtnCloseStr);
	XXml::getXmlAsString(rootNode,"sendModeCmbStr",m_sendModeCmbStr);
	XXml::getXmlAsString(rootNode,"sendAsMsgStr",m_sendAsMsgStr);
	XXml::getXmlAsString(rootNode,"supportACKModeStr",m_supportACKModeStr);
	XXml::getXmlAsString(rootNode,"clearRecvBtnStr",m_clearRecvBtnStr);
	XXml::getXmlAsString(rootNode,"openRBtnOpenStr",m_openRBtnOpenStr);
	XXml::getXmlAsString(rootNode,"openRBtnCloseStr",m_openRBtnCloseStr);
	XXml::getXmlAsString(rootNode,"saveBtnStr",m_saveBtnStr);
	XXml::getXmlAsString(rootNode,"readBtnStr",m_readBtnStr);
	XXml::getXmlAsString(rootNode,"textIPEdtCommentStr",m_textIPEdtCommentStr);
	XXml::getXmlAsString(rootNode,"textPortEdtCommentStr",m_textPortEdtCommentStr);
	XXml::getXmlAsString(rootNode,"openBtnCommentStr",m_openBtnCommentStr);
	XXml::getXmlAsString(rootNode,"addBtnCommentStr",m_addBtnCommentStr);
	XXml::getXmlAsString(rootNode,"delBtnCommentStr",m_delBtnCommentStr);
	XXml::getXmlAsString(rootNode,"clearBtnCommentStr",m_clearBtnCommentStr);
	XXml::getXmlAsString(rootNode,"modifyBtnCommentStr",m_modifyBtnCommentStr);
	XXml::getXmlAsString(rootNode,"textDataEdtCommentStr",m_textDataEdtCommentStr);
	XXml::getXmlAsString(rootNode,"textDataCmbCommentStr",m_textDataCmbCommentStr);
	XXml::getXmlAsString(rootNode,"textAddressEdtCommentStr",m_textAddressEdtCommentStr);
	XXml::getXmlAsString(rootNode,"textTimesEdtCommentStr",m_textTimesEdtCommentStr);
	XXml::getXmlAsString(rootNode,"textSpacingEdtCommentStr",m_textSpacingEdtCommentStr);
	XXml::getXmlAsString(rootNode,"sendModeCmbCommentStr",m_sendModeCmbCommentStr);
	XXml::getXmlAsString(rootNode,"sendAsMsgCommentStr",m_sendAsMsgCommentStr);
	XXml::getXmlAsString(rootNode,"sendBtnCommentStr",m_sendBtnCommentStr);
	XXml::getXmlAsString(rootNode,"textRPortEdtCommentStr",m_textRPortEdtCommentStr);
	XXml::getXmlAsString(rootNode,"openRBtnCommentStr",m_openRBtnCommentStr);
	XXml::getXmlAsString(rootNode,"supportACKModeCommentStr",m_supportACKModeCommentStr);
	XXml::getXmlAsString(rootNode,"clearRecvBtnCommentStr",m_clearRecvBtnCommentStr);
	XXml::getXmlAsString(rootNode,"languageCmbCommentStr",m_languageCmbCommentStr);
	XXml::getXmlAsString(rootNode,"codeModeCmbCommentStr",m_codeModeCmbCommentStr);
	XXml::getXmlAsString(rootNode,"saveBtnCommentStr",m_saveBtnCommentStr);
	XXml::getXmlAsString(rootNode,"readBtnCommentStr",m_readBtnCommentStr);
	XXml::getXmlAsString(rootNode,"addKMBtnCommentStr",m_addKMBtnCommentStr);
	XXml::getXmlAsString(rootNode,"delKMBtnCommentStr",m_delKMBtnCommentStr);
	XXml::getXmlAsString(rootNode,"clearKMBtnCommentStr",m_clearKMBtnCommentStr);
	XXml::getXmlAsString(rootNode,"modifyKMBtnCommentStr",m_modifyKMBtnCommentStr);
	XXml::getXmlAsString(rootNode,"keySelectCmbCommentStr",m_keySelectCmbCommentStr);
	XXml::getXmlAsString(rootNode,"keyStateCmbCommentStr",m_keyStateCmbCommentStr);
	XXml::getXmlAsString(rootNode,"oscDataEdtCommentStr",m_oscDataEdtCommentStr);
	XXml::getXmlAsString(rootNode,"oscDataCmbCommentStr",m_oscDataCmbCommentStr);
	XXml::getXmlAsString(rootNode,"oscAddressEdtCommentStr",m_oscAddressEdtCommentStr);

	return XTrue;
}
XBool GLanguage::saveToFile(const std::string &filename)	//从文件中读取字符串
{//下面从字符串中读取相关的字符串
	TiXmlDocument doc;
	TiXmlDeclaration declaration("1.0","gb2312","yes"); 
	doc.InsertEndChild(declaration);
	TiXmlElement elmRoot("root");

	if(!XXml::addLeafNode(elmRoot,"tabTitileStr",m_tabTitileStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openBtnOpenStr",m_openBtnOpenStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openBtnCloseStr",m_openBtnCloseStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"addKMBtnStr",m_addKMBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"delKMBtnStr",m_delKMBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearKMBtnStr",m_clearKMBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"modifyKMBtnStr",m_modifyKMBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscDataTxtStr",m_oscDataTxtStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscTypeStr",m_oscTypeStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscAddressStr",m_oscAddressStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"addBtnStr",m_addBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"delBtnStr",m_delBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearBtnStr",m_clearBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"modifyBtnStr",m_modifyBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textDataStr",m_textDataStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textTypeStr",m_textTypeStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textAddressStr",m_textAddressStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textTimesStr",m_textTimesStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textSpacingStr",m_textSpacingStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendBtnOpenStr",m_sendBtnOpenStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendBtnCloseStr",m_sendBtnCloseStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendModeCmbStr",m_sendModeCmbStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendAsMsgStr",m_sendAsMsgStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"supportACKModeStr",m_supportACKModeStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearRecvBtnStr",m_clearRecvBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openRBtnOpenStr",m_openRBtnOpenStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openRBtnCloseStr",m_openRBtnCloseStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"saveBtnStr",m_saveBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"readBtnStr",m_readBtnStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textIPEdtCommentStr",m_textIPEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textPortEdtCommentStr",m_textPortEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openBtnCommentStr",m_openBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"addBtnCommentStr",m_addBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"delBtnCommentStr",m_delBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearBtnCommentStr",m_clearBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"modifyBtnCommentStr",m_modifyBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textDataEdtCommentStr",m_textDataEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textDataCmbCommentStr",m_textDataCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textAddressEdtCommentStr",m_textAddressEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textTimesEdtCommentStr",m_textTimesEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textSpacingEdtCommentStr",m_textSpacingEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendModeCmbCommentStr",m_sendModeCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendAsMsgCommentStr",m_sendAsMsgCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"sendBtnCommentStr",m_sendBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"textRPortEdtCommentStr",m_textRPortEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"openRBtnCommentStr",m_openRBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"supportACKModeCommentStr",m_supportACKModeCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearRecvBtnCommentStr",m_clearRecvBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"languageCmbCommentStr",m_languageCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"codeModeCmbCommentStr",m_codeModeCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"saveBtnCommentStr",m_saveBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"readBtnCommentStr",m_readBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"addKMBtnCommentStr",m_addKMBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"delKMBtnCommentStr",m_delKMBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"clearKMBtnCommentStr",m_clearKMBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"modifyKMBtnCommentStr",m_modifyKMBtnCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"keySelectCmbCommentStr",m_keySelectCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"keyStateCmbCommentStr",m_keyStateCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscDataEdtCommentStr",m_oscDataEdtCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscDataCmbCommentStr",m_oscDataCmbCommentStr)) return XFalse;
	if(!XXml::addLeafNode(elmRoot,"oscAddressEdtCommentStr",m_oscAddressEdtCommentStr)) return XFalse;
		
	if(doc.InsertEndChild(elmRoot) == NULL) return false;
	if(!doc.SaveFile(filename)) return XFalse;
	return XTrue;
}
XBool GLanguage::setCurrentLanguage(XLanguage language,const std::string &filename)
{//从指定文件中读取语言信息
	if(!loadFromFile(filename)) return XFalse;
	m_currentLanguage = language;
	return XTrue;
}