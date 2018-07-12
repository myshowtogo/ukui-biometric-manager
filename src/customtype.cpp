#include "customtype.h"
#include <QDBusMetaType>

void registerCustomTypes()
{
	qDBusRegisterMetaType<DeviceInfo>();
    qDBusRegisterMetaType<FeatureInfo>();
	qDBusRegisterMetaType<QList<QDBusVariant> >();
    qDBusRegisterMetaType<SearchResult>();
}

/* For the type DeviceInfo */
QDBusArgument &operator<<(QDBusArgument &argument, const DeviceInfo &deviceInfo)
{
    argument.beginStructure();
    argument << deviceInfo.device_id << deviceInfo.device_shortname
		<< deviceInfo.device_fullname << deviceInfo.driver_enable
		<< deviceInfo.device_available
		<< deviceInfo.biotype << deviceInfo.stotype
		<< deviceInfo.eigtype << deviceInfo.vertype
		<< deviceInfo.idtype << deviceInfo.bustype
		<< deviceInfo.dev_status << deviceInfo.ops_status;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DeviceInfo &deviceInfo)
{
    argument.beginStructure();
    argument >> deviceInfo.device_id >> deviceInfo.device_shortname
		>> deviceInfo.device_fullname >> deviceInfo.driver_enable
		>> deviceInfo.device_available
		>> deviceInfo.biotype >> deviceInfo.stotype
		>> deviceInfo.eigtype >> deviceInfo.vertype
		>> deviceInfo.idtype >> deviceInfo.bustype
		>> deviceInfo.dev_status >> deviceInfo.ops_status;
    argument.endStructure();
    return argument;
}

/* For the type FeatureInfo */
QDBusArgument &operator<<(QDBusArgument &argument, const FeatureInfo &featureInfo)
{
    argument.beginStructure();
    argument << featureInfo.uid << featureInfo.biotype
        << featureInfo.device_shortname << featureInfo.index
        << featureInfo.index_name;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, FeatureInfo &featureInfo)
{
    argument.beginStructure();
    argument >> featureInfo.uid >> featureInfo.biotype
        >> featureInfo.device_shortname >> featureInfo.index
        >> featureInfo.index_name;
    argument.endStructure();
    return argument;
}

/* For the type SearchResult */
QDBusArgument &operator<<(QDBusArgument &argument, const SearchResult &ret)
{
    argument.beginStructure();
    argument << ret.uid << ret.index << ret.indexName;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, SearchResult &ret)
{
    argument.beginStructure();
    argument >> ret.uid >> ret.index >> ret.indexName;
    argument.endStructure();
    return argument;
}


QString EnumToString::transferBioType(int type)
{
    switch(type) {
    case BIOTYPE_FINGERPRINT:
        return tr("FingerPrint");
    case BIOTYPE_FINGERVEIN:
        return tr("FingerPrint");
    case BIOTYPE_IRIS:
        return tr("Iris");
    case BIOTYPE_FACE:
        return tr("Face");
    case BIOTYPE_VOICEPRINT:
        return tr("VoicePrint");
    }
    return QString();
}
QString EnumToString::transferVerifyType(int type)
{
    switch(type) {
    case VERIFY_HARDWARE:
        return tr("Hardware Verification");
    case VERIFY_SOFTWARE:
        return tr("Software Verification");
    case VERIFY_MIX:
        return tr("Mix Verification");
    case VERIFY_OTHER:
        return tr("Other Verification");
    }
    return QString();
}
QString EnumToString::transferStorageType(int type)
{
    switch(type) {
    case STORAGE_DEVICE:
        return tr("Device Storage");
    case STORAGE_OS:
        return tr("OS Storage");
    case STORAGE_MIX:
        return tr("Mix Storage");
    }
    return QString();
}
QString EnumToString::transferBusType(int type)
{
    switch(type) {
    case BUS_SERIAL:
        return tr("Serial");
    case BUS_USB:
        return tr("USB");
    case BUS_PCIE:
        return tr("PCIE");
    case BUS_ANY:
        return tr("Any");
    case BUS_OTHER:
        return tr("Other");
    }
    return QString();
}
QString EnumToString::transferIdentifyType(int type)
{
    switch(type) {
    case VERIFY_HARDWARE:
        return tr("Hardware Identification");
    case VERIFY_SOFTWARE:
        return tr("Software Identification");
    case VERIFY_MIX:
        return tr("Mix Identification");
    case VERIFY_OTHER:
        return tr("Other Identification");
    }
    return QString();
}

