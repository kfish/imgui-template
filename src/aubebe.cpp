#include "aubebe.h"

#include <iostream>

#include "imgui.h"
#include "ImGuiFileDialog.h"

void filedialog() {
  // open Dialog Simple
  if (ImGui::Button("Open File Dialog")) {
    IGFD::FileDialogConfig config;
	config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cpp,.h,.hpp", config);
  }
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
      std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      // action
      std::cout << "filePathName: " << filePathName << std::endl;
      std::cout << "filePath: " << filePath << std::endl;
    }

    // close
    ImGuiFileDialog::Instance()->Close();
  }
}

void AuBeBe::ShowMainWindow(bool* p_open)
{
    ImGui::Begin("AuBeBe", p_open);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("Hello from aubebe!");
    if (ImGui::Button("Close Me"))
        *p_open = false;

    filedialog();

    ImGui::End();
}
