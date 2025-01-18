library_name = input("Library Name: ")
module_name  = input("Module Name: ")
class_name  = input("Class Name: ")
parent_module_name = input("Parent Module Name: ")
parent_class_name  = input("Parent Class Name: ")

module_names = [("cstm" ,module_name.lower()), ("Cstm", module_name.lower().capitalize()),  ("CSTM", module_name.upper())]
class_names = [("clss" ,class_name.lower()), ("Clss", class_name.lower().capitalize()),  ("CLSS", class_name.upper())]
parent_module_names = [("parpar" ,parent_module_name.lower()), ("Parpar", parent_module_name.lower().capitalize()),  ("PARPAR", parent_module_name.upper())]
parent_class_names = [("namnam" ,parent_class_name.lower()), ("Namnam", parent_class_name.lower().capitalize()),  ("NAMNAM", parent_class_name.upper())]

input_file_h = open("cstm-clss.h", "r")
input_file_c = open("cstm-clss.c", "r")

h_content = input_file_h.read()
c_content = input_file_c.read()

input_file_h.close()
input_file_c.close()

for (old, new) in  module_names + parent_module_names + class_names + parent_class_names + [("liblib.h", library_name)]:
        c_content = c_content.replace(old, new)
        h_content = h_content.replace(old, new)

h_content = "\n".join((h_content.splitlines()[8:]))
c_content = "\n".join((c_content.splitlines()[8:]))

output_file_h = open(f"{module_names[0][1]}-{class_names[0][1]}.h", "w");
output_file_c = open(f"{module_names[0][1]}-{class_names[0][1]}.c", "w");

print(h_content, file=output_file_h);
print(c_content, file=output_file_c);

output_file_h.close()
output_file_c.close()
