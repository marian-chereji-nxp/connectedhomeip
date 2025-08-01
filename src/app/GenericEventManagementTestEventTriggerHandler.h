/*
 *
 *    Copyright (c) 2024 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <app/TestEventTriggerDelegate.h>
#include <app/clusters/general-diagnostics-server/general-diagnostics-cluster.h>

namespace chip {
namespace app {

class GenericEventManagementTestEventTriggerHandler : public TestEventTriggerHandler
{
public:
    GenericEventManagementTestEventTriggerHandler(Clusters::GeneralDiagnosticsCluster * generalDiagnosticsClusterInstance) :
        mGeneralDiagnosticsCluster(generalDiagnosticsClusterInstance)
    {}

    Clusters::GeneralDiagnosticsCluster * GetGeneralDiagnosticsClusterInstance() { return mGeneralDiagnosticsCluster; }

    void SetGeneralDiagnosticsClusterInstance(Clusters::GeneralDiagnosticsCluster * generalDiagnosticsClusterInstance)
    {
        mGeneralDiagnosticsCluster = generalDiagnosticsClusterInstance;
    }

protected:
    CHIP_ERROR HandleFillUpEventLoggingBufferEventTriger();

private:
    void FillUpEventLoggingBufferWithFakeSoftwareFault(size_t bufferSize);
    virtual void TriggerSoftwareFaultEvent(const char * faultRecordString) = 0;
    Clusters::GeneralDiagnosticsCluster * mGeneralDiagnosticsCluster       = nullptr;
};

} // namespace app
} // namespace chip
