// -------------------------------------------------------------------------
//    @FileName         :    NFCObject.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2012-12-17
//    @Module           :    NFCObject
//
// -------------------------------------------------------------------------

#ifndef _NFC_OBJECT_H_
#define _NFC_OBJECT_H_

#include <iostream>
#include <string>
#include "NFComm/NFCore/NFIObject.h"
#include "NFComm/NFCore/NFIRecordManager.h"
#include "NFComm/NFCore/NFIHeartBeatManager.h"
#include "NFComm/NFCore/NFIPropertyManager.h"

class NFCObject
    : public NFIObject
{
public:
    NFCObject(NFIDENTID self, NFIPluginManager* pLuginManager);
    virtual ~NFCObject();

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute(const float fLastTime, const float fAllTime);

    ///////////////////////////////////////////////////////////////////////

    virtual NFIDENTID Self();

    virtual bool FindHeartBeat(const std::string& strHeartBeatName);

    virtual bool RemoveHeartBeat(const std::string& strHeartBeatName);

    /////////////////////////////////////////////////////////////////

    virtual bool FindProperty(const std::string& strPropertyName);

    virtual bool SetPropertyInt(const std::string& strPropertyName, const NFINT64 nValue);
    virtual bool SetPropertyFloat(const std::string& strPropertyName,  const float fValue);
    virtual bool SetPropertyDouble(const std::string& strPropertyName, const double dwValue);
    virtual bool SetPropertyString(const std::string& strPropertyName, const std::string& strValue);
    virtual bool SetPropertyObject(const std::string& strPropertyName, const NFIDENTID& obj);

    virtual NFINT64 GetPropertyInt(const std::string& strPropertyName);
    virtual float GetPropertyFloat(const std::string& strPropertyName);
    virtual double GetPropertyDouble(const std::string& strPropertyName);
    virtual const std::string& GetPropertyString(const std::string& strPropertyName);
    virtual NFIDENTID GetPropertyObject(const std::string& strPropertyName);

    virtual bool FindRecord(const std::string& strRecordName);

    virtual bool SetRecordInt(const std::string& strRecordName, const int nRow, const int nCol, const NFINT64 nValue);
    virtual bool SetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol,  const float fValue);
    virtual bool SetRecordDouble(const std::string& strRecordName, const int nRow, const int nCol, const double dwValue);
    virtual bool SetRecordString(const std::string& strRecordName, const int nRow, const int nCol, const std::string& strValue);
    virtual bool SetRecordObject(const std::string& strRecordName, const int nRow, const int nCol, const NFIDENTID& obj);

    virtual bool SetRecordInt(const std::string& strRecordName, const int nRow, const std::string& strColTag, const NFINT64 value);
    virtual bool SetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag, const float value);
    virtual bool SetRecordDouble(const std::string& strRecordName, const int nRow, const std::string& strColTag, const double value);
    virtual bool SetRecordString(const std::string& strRecordName, const int nRow, const std::string& strColTag, const std::string& value);
    virtual bool SetRecordObject(const std::string& strRecordName, const int nRow, const std::string& strColTag, const NFIDENTID& value);

    virtual NFINT64 GetRecordInt(const std::string& strRecordName, const int nRow, const int nCol);
    virtual float GetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol);
    virtual double GetRecordDouble(const std::string& strRecordName, const int nRow, const int nCol);
    virtual const std::string& GetRecordString(const std::string& strRecordName, const int nRow, const int nCol);
    virtual NFIDENTID GetRecordObject(const std::string& strRecordName, const int nRow, const int nCol);

    virtual NFINT64 GetRecordInt(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual float GetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual double GetRecordDouble(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual const std::string& GetRecordString(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual NFIDENTID GetRecordObject(const std::string& strRecordName, const int nRow, const std::string& strColTag);

    virtual std::shared_ptr<NFIComponent> AddComponent(const std::string& strComponentName, const std::string& strLanguageName);
    virtual std::shared_ptr<NFIComponent> FindComponent(const std::string& strComponentName);

    virtual std::shared_ptr<NFIRecordManager> GetRecordManager();
    virtual std::shared_ptr<NFIHeartBeatManager> GetHeartBeatManager();
    virtual std::shared_ptr<NFIPropertyManager> GetPropertyManager();
    virtual std::shared_ptr<NFIComponentManager> GetComponentManager();

protected:
    virtual bool AddRecordCallBack(const std::string& strRecordName, const RECORD_EVENT_FUNCTOR_PTR& cb);

    virtual bool AddPropertyCallBack(const std::string& strCriticalName, const PROPERTY_EVENT_FUNCTOR_PTR& cb);

    virtual bool AddHeartBeat(const std::string& strHeartBeatName, const HEART_BEAT_FUNCTOR_PTR& cb, const NFIDataList& var, const float fTime, const int nCount);

private:
    NFIDENTID mSelf;

    std::shared_ptr<NFIRecordManager> m_pRecordManager;
    std::shared_ptr<NFIHeartBeatManager> m_pHeartBeatManager;
    std::shared_ptr<NFIPropertyManager> m_pPropertyManager;
    std::shared_ptr<NFIComponentManager> m_pComponentManager;

    NFIPluginManager* m_pPluginManager;
};

#endif