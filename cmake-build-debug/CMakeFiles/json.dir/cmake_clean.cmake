file(REMOVE_RECURSE
  "libjson.pdb"
  "libjson.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/json.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
