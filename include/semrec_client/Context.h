/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014, Jan Winkler, Institute for Artificial
 *  Intelligence, Universität Bremen.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Institute for Artificial Intelligence,
 *     Universität Bremen, nor the names of its contributors may be
 *     used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/** \author Jan Winkler */


#ifndef __CONTEXT_H__
#define __CONTEXT_H__


// System
#include <string>

// Designators
#include <designators/Designator.h>

// Private
#include <semrec_client/BeliefstateClient.h>


namespace semrec_client {
  class Context : public designator_integration::Designator {
  private:
    int m_nContextID;
    BeliefstateClient* m_bsclClient;
    
  protected:
    void setID(int nContextID);
    
  public:
    Context(BeliefstateClient* bsclClient, int nContextID);
    Context(BeliefstateClient* bsclClient, std::string strContextName, double dTimeStamp = -1);
    Context(BeliefstateClient* bsclClient, std::string strContextName, std::string strClassNamespace = "", std::string strClass = "", double dTimeStamp = -1);
    ~Context();
    
    int id();
    
    void end(bool bSuccess = true, double dTimeStamp = -1);
    
    Context* startContext(std::string strContextName, std::string strClassNamespace = "", std::string strClass = "", double dTimeStamp = -1);
    void annotateParameter(std::string strKey, std::string strValue);
    void annotateParameter(std::string strKey, float fValue);
    void addObject(Object* objAdd, std::string strProperty = "");
    void addDesignator(designator_integration::Designator* cdAdd, std::string strAnnotation = "");
    void addDesignator(designator_integration::Designator* cdAdd, std::string strProperty="", std::string strClassNamespace="", std::string strClass="");
    void discreteEvent(std::string strEventName, std::string strClassNamespace = "", std::string strClass = "", bool bSuccess = true, double dTimeStamp = -1);
  };
}


#endif /* __CONTEXT_H__ */
