#include <semrec_client/Context.h>


namespace semrec_client {
  Context::Context(BeliefstateClient* bsclClient, int nContextID) {
    m_bsclClient = bsclClient;
    
    this->setID(nContextID);
  }
  
  Context::Context(BeliefstateClient* bsclClient, std::string strContextName, double dTimeStamp) {
    m_bsclClient = bsclClient;
    
    this->setID(bsclClient->startContext(strContextName, -1, dTimeStamp));
  }
  
  Context::Context(BeliefstateClient* bsclClient, std::string strContextName, std::string strClassNamespace, std::string strClass, double dTimeStamp) {
    m_bsclClient = bsclClient;
    
    this->setID(m_bsclClient->startContext(strContextName, -1, strClassNamespace, strClass, dTimeStamp));
  }
  
  Context::~Context() {
  }
  
  void Context::end(bool bSuccess, double dTimeStamp) {
    m_bsclClient->endContext(this->id(), bSuccess, dTimeStamp, true);
  }
  
  void Context::setID(int nContextID) {
    m_nContextID = nContextID;
  }
  
  int Context::id() {
    return m_nContextID;
  }
  
  Context* Context::startContext(std::string strContextName, std::string strClassNamespace, std::string strClass, double dTimeStamp) {
    return new Context(m_bsclClient, m_bsclClient->startContext(strContextName, this->id(), strClassNamespace, strClass, dTimeStamp));
  }
  
  void Context::annotateParameter(std::string strKey, std::string strValue) {
    m_bsclClient->annotateParameter(strKey, strValue, this->id());
  }
  
  void Context::annotateParameter(std::string strKey, float fValue) {
    m_bsclClient->annotateParameter(strKey, fValue, this->id());
  }
  
  void Context::annotateResource(std::string strProperty, std::string strURI, std::string strNamespace) {
    m_bsclClient->annotateResource(strProperty, strURI, strNamespace, this->id());
  }
  
  void Context::addObject(Object* objAdd, std::string strProperty) {
    m_bsclClient->addObject(objAdd, strProperty, this->id());
  }
  
  void Context::addDesignator(designator_integration::Designator* cdAdd, std::string strAnnotation) {
    m_bsclClient->addDesignator(cdAdd, strAnnotation, this->id());
  }

  void Context::addDesignator(designator_integration::Designator* cdAdd, std::string strProperty, std::string strClassNamespace, std::string strClass) {
    m_bsclClient->addDesignator(cdAdd, strProperty, strClassNamespace, strClass, this->id());
  }

  
  void Context::discreteEvent(std::string strEventName, std::string strClassNamespace, std::string strClass, bool bSuccess, double dTimeStamp) {
    m_bsclClient->discreteEvent(strEventName, this->id(), strClassNamespace, strClass, bSuccess, dTimeStamp, true);
  }
}
