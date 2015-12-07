// -------------------------------------------------------------------------
//    @FileName      :    NFCPropertyTrailModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-09-30
//    @Module           :    NFCPropertyTrailModule
//
// -------------------------------------------------------------------------

#ifndef _NFC_PROPERTY_TRAIL_MODULE_H_
#define _NFC_PROPERTY_TRAIL_MODULE_H_

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIGameLogicModule.h"
#include "NFComm/NFPluginModule/NFIEventProcessModule.h"
#include "NFComm/NFPluginModule/NFIPropertyModule.h"
#include "NFComm/NFPluginModule/NFIElementInfoModule.h"
#include "NFComm/NFPluginModule/NFILogicClassModule.h"
#include "NFComm/NFPluginModule/NFIPropertyConfigModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIPropertyTrailModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"

class NFCPropertyTrailModule
    : public NFIPropertyTrailModule
{
public:
    NFCPropertyTrailModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCPropertyTrailModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute( const float fLasFrametime, const float fStartedTime );
    virtual bool AfterInit();

	virtual void StartTrail(const NFGUID self);
	virtual void EndTrail(const NFGUID self);

protected:

	int LogObjectData( const NFGUID& self);
	int TrailObjectData( const NFGUID& self);

	int OnObjectPropertyEvent( const NFGUID& self, const std::string& strPropertyName, const NFIDataList::TData& oldVar, const NFIDataList::TData& newVar );

	int OnObjectRecordEvent( const NFGUID& self, const RECORD_EVENT_DATA& xEventData, const NFIDataList& oldVar, const NFIDataList& newVar);

private:

	NFIEventProcessModule* m_pEventProcessModule;
	NFIKernelModule* m_pKernelModule;
	NFIPropertyConfigModule* m_pPropertyConfigModule;
	NFIElementInfoModule* m_pElementInfoModule;
	NFILogicClassModule* m_pLogicClassModule;
	NFILogModule* m_pLogModule;
};


#endif