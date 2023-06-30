pdf_files_path = "D:/Note/CodingPractice/Essence"
output_path = "D:/Note/CodingPractice/Essence/C++复习资料.pdf"

import os

pdf_list = []
for dirs in os.listdir(pdf_files_path):
    if(os.path.isdir(pdf_files_path + "/" + dirs)):
        for fis in os.listdir(pdf_files_path + "/" + dirs):
            if(os.path.splitext(fis)[1] == ".pdf"):
                full_path = pdf_files_path + "/" + dirs + "/" + fis
                pdf_list.append(full_path)
                
from PyPDF2 import PdfMerger
file_merger = PdfMerger()
for pdf in pdf_list:
    file_merger.append(pdf)   
    
file_merger.write(output_path)