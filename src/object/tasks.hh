/**
 ** \file object/tasks.hh
 ** \brief Object module related tasks.
 */

#pragma once

#include <task/libtask.hh>

namespace object
{

  /// The Tasks of the object module.
  namespace tasks
  {

    TASK_GROUP("Object");

    /// Enable object extensions.
    BOOLEAN_TASK_DECLARE("o|object", "enable object extensions",
                         enable_object_extensions_p, "");

    /// Parse the input file, allowing objects.
    TASK_DECLARE("object-parse", "parse a file, allowing objects",
                 object_parse, "object parse");

    //fix by caradi_c
    TASK_DECLARE("object-bindings-compute", "", bind_obj, "object_parse");




  } // namespace tasks

}// namespace object
