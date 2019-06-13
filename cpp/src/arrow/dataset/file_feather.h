// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <memory>
#include <string>

#include "arrow/dataset/file_base.h"
#include "arrow/dataset/type_fwd.h"
#include "arrow/dataset/visibility.h"

namespace arrow {
namespace dataset {

class ARROW_DS_EXPORT FeatherScanOptions : public FileScanOptions {
 public:
  std::string file_type() const override;
};

class ARROW_DS_EXPORT FeatherWriterOptions : public FileWriteOptions {
 public:
  std::string file_type() const override;
};

/// \brief A FileFormat implementation that reads from Feather (Arrow
/// IPC protocol) files
class ARROW_DS_EXPORT FeatherFileFormat : public FileFormat {
 public:
  std::string name() const override;

  /// \brief Return true if the given file extension
  bool IsKnownExtension(const std::string& ext) const override;

  /// \brief Open a file for scanning
  Status ScanFile(const FileSource& location, std::shared_ptr<ScanOptions> scan_options,
                  std::shared_ptr<ScanContext> scan_context,
                  std::unique_ptr<ScanTaskIterator>* out) const override;
};

}  // namespace dataset
}  // namespace arrow
