// a1 指向此结构体的实例
struct SmartExportManager // 为该结构体赋予一个推测的名称
{
    //======================================================================
    // 偏移量: +0 到 +31 (共 32 字节)
    // 作用: 存储处理和转换后的最终导出设置，由智能指针管理
    //======================================================================

    // boost::shared_ptr<SmartExport::ExportSettingCollection> artboardSettings;
    // (用于画板导出的设置集合)
    SmartExport::ExportSettingCollection* artboardSettings_data_ptr;    // 偏移量: +0 (8 字节)
    boost::detail::sp_counted_base* artboardSettings_control_block; // 偏移量: +8 (8 字节)

    // boost::shared_ptr<SmartExport::ExportSettingCollection> assetSettings;
    // (用于资产导出的设置集合)
    SmartExport::ExportSettingCollection* assetSettings_data_ptr;       // 偏移量: +16 (8 字节)
    boost::detail::sp_counted_base* assetSettings_control_block;  // 偏移量: +24 (8 字节)


    //======================================================================
    // 偏移量: +32 到 +79 (共 48 字节)
    // 作用: 存储从文件中加载的原始预设信息（未经最终处理）
    //======================================================================
    
    // 这是一个内部子结构，我们推测其为 PresetInfo
    struct PresetInfo // (大小为 24 字节)
    {
        AIUnicodeString* presetName;         // 偏移量: +0 (例如 "Last Used Artboard Export Settings")
        AIFilePath* presetFilePath;     // 偏移量: +8 (预设文件的路径对象)
        void* presetCollection;   // 偏移量: +16 (指向 AIAttrCollection 的句柄)
    };

    PresetInfo artboardPresetInfo; // 偏移量: +32 (24 字节)
    PresetInfo assetPresetInfo;    // 偏移量: +56 (24 字节)


    //======================================================================
    // 偏移量: +80 及之后
    // 作用: 其他相关的管理器或数据成员
    //======================================================================

    void* unknown_manager_A;      // 偏移量: +80 (8 字节), 指向一个 0x58 (88) 字节大小的已分配对象

    void* unknown_ptr_88;         // 偏移量: +88 (8 字节), 初始化为 std::vector
    void* unknown_ptr_96;         // 偏移量: +96 (8 字节), 初始化为 std::vector

    int    unknown_flag_or_enum_104; // 偏移量: +104 (4 字节), 被赋值为 7
    int    unknown_flag_or_enum_108; // 偏移量: +108 (4 字节), 也被赋值为 7
    char   padding_112[8];         // 偏移量: +112 (8 字节), 填充或未使用
    void* unknown_manager_B;      // 偏移量: +120 (8 字节), 指向一个 0x50 (80) 字节大小的已分配对象


    void* unknown_ptr_128;        // 偏移量: +128 (8 字节), 初始化为 0   导出模式选择  1 资源导出模式 0画板导出模式

    void* unknown_manager_C;      // 偏移量: +136 (8 字节), 指向一个 0x38 (56) 字节大小的已分配对象
    void* unknown_ptr_144;        // 偏移量: +144 (8 字节), 初始化为 0
    
    // ... 结构体可能还有更多成员
};


// Adobe Illustrator 插件传递的标准入口参数，通常称为 "Plugin Globals"
struct PluginGlobals // 为 a1 指向的结构体赋予一个推测的名称
{
    //======================================================================
    // 偏移量: +0 to +~500 (标准 Illustrator 插件头部)
    //======================================================================
    
    SPMessageData* messageData;         // 偏移量: +0 (a1[0]), 指向消息数据
    SPBasicSuite* sSPBasic;             // 偏移量: +8 (a1[1]), 基础套件指针，用于获取其他套件
    SPPluginRef selfPluginRef;          // 偏移量: +16 (a1[2]), 插件自身的引用

    //a1+272  是否刷新获取全部组件
    void bCheckAndRefreshSuites;
    //======================================================================
    // 偏移量: +312, +320
    // 由消息处理器 sub_180039710 使用的通知器句柄
    //======================================================================
    
    AINotifierHandle hSomeNotifier_1;   // 偏移量: +312 (a1[39])
    AINotifierHandle hSomeNotifier_2;   // 偏移量: +320 (a1[40])

    //======================================================================
    // 偏移量: +336 (a1[42])
    // 作用: 存储我们自己创建的核心管理器
    //======================================================================
    SmartExportManager* pSmartExportManager; // 偏移量: +336 (8 字节), 指向 SmartExportManager 实例
    //偏移量+352 (推测的面板指针)
    void pSmartExportPanel
    //======================================================================
    // 偏移量: +504 (a1[63])
    // 作用: 存储 UI 相关的句柄
    //======================================================================
    AIMenuItemHandle    hMenuAssetExport; // 偏移量: +504 (8 字节), “资源导出”菜单项的句柄


    //======================================================================
    // 偏移量: +512 to +607 (a1[64] to a1[75])
    // 作用: 存储各种事件的通知器 (Notifier) 句柄
    // 由 sub_18004EF90 函数负责注册和填充
    //======================================================================
    AINotifierHandle    hAssetAddedNotifier;           // 偏移量: +512
    AINotifierHandle    hAssetsDeletedNotifier;        // 偏移量: +520
    AINotifierHandle    hAssetUndoNotifier;            // 偏移量: +528
    AINotifierHandle    hAssetRenamedNotifier;         // 偏移量: +536
    AINotifierHandle    hAppShutdownNotifier;          // 偏移量: +544
    AINotifierHandle    hDocAboutToCloseNotifier;      // 偏移量: +552
    AINotifierHandle    hDocChangedNotifier;           // 偏移量: +560
    AINotifierHandle    hArtPropertiesChangedNotifier; // 偏移量: +568
    AINotifierHandle    hSelectionChangedNotifier;     // 偏移量: +576
    AINotifierHandle    hAppActivatedNotifier;         // 偏移量: +584
    AINotifierHandle    hAppDeactivatedNotifier;       // 偏移量: +592
    AINotifierHandle    hTaskManagerUIInitNotifier;    // 偏移量: +600


    //======================================================================
    // 偏移量: +608 (a1[76])
    // 作用: 插件自定义套件(Suite)
    //======================================================================
    
    // 指向一个由插件自身定义的函数表 (Function Table)，用于向其他插件或脚本暴露功能。
    // 由 Plg_Init 通过 gSPSuitesSuite->AddSuite(...) 创建。
    // 由 sub_180052A60 (插件终止函数) 负责释放。
    AISmartExportUISuite* pExportUISuite; // 偏移量: +608

    //======================================================================
    // 偏移量: +816 (a1[102])
    // 作用: 存储初始化标志位
    //======================================================================
    bool                isBIBInitialized; // 偏移量: +816 (1 字节), 标志 Adobe Bridge (BIB) 库是否已初始化


    //======================================================================
    // 偏移量: +824 (a1[103])
    // 作用: 存储 UI 对话框客户端接口
    //======================================================================
    MultiEveDialogUIClientInterfaceImplPNG8* pDialogClient; // 偏移量: +824 (8 字节)
                                                            // 由 sub_180050860 创建和缓存
    // PNG8 格式的设置与状态数据 (104字节)
    // 由 sub_180051EB0 创建，并注册到并发框架中
    PNG8_Settings_And_State* pPNG8_Settings; // 偏移量: +832

    // ... 结构体可能还有更多成员
};

#pragma once

// 前向声明 (Forward Declarations)
// 声明了该类所依赖的其他自定义类或UI框架中的类
namespace dvacore { namespace utility { class RefCountedObjectWithWeakPtr; } }
namespace dvaui { namespace controls {
    class UI_MultiColumnTree;
    class UI_Button;
    class UI_StaticText;
    class UI_StaticImage;
    class UI_Checkbox;
}}

class PreviewCreator;
class SettingsManager;
class ExportJob; 
class AIUIBasePanel; // 假设它继承自一个基础面板类

/**
 * @class SmartExportPanel
 * @brief 智能导出功能的主UI面板类。
 *
 * 该类的实例由工厂函数 InitAssetExportUi (sub_1800502D0) 以单例模式创建，
 * 并存储在 PluginGlobals->pSmartExportPanel (偏移量 +352) 中。
 * 它负责构建、管理和响应“资源导出”面板中的所有UI交互。
 * 总大小: 0x158 (344) 字节。
 */
struct SmartExportPanel 
{
    //======================================================================
    // 成员变量 (Member Variables)
    //======================================================================

    // --- 核心逻辑与数据模块 ---
    // 偏移量: 0x38 / 56   [新增细节]
    void* m_pScrollState; // 用于在刷新前后保存和恢复列表滚动位置

    // 偏移量: 0x40 / 64   [新增细节]
    dvacore::utility::RefCountedObjectWithWeakPtr* m_pScrollStateRefCounter; // 滚动位置状态的智能指针控制块

    // 偏移量: 0x88 / 136
    SmartExport::PreviewCreator* m_pPreviewCreator;// 由 RefreshContents 间接调用以刷新预览

    // 偏移量: 0x90 / 144
    SmartExport::SettingsManager* m_pSettingsManager; // 由 RefreshContents 间接调用以刷新设置

    // 偏移量: 0x98 / 152
    dvacore::utility::RefCountedObjectWithWeakPtr* m_pMCTDataProvider; // 资源列表的数据提供者

     // 偏移量: 0xB8 / 184
    dvacore::utility::RefCountedObjectWithWeakPtr* m_pFlyoutMenuManager; 
    // --- 主要UI控件指针 ---

    // 偏移量: 0xC0 / 192
    dvacore::controls::UI_MultiColumnTree* m_pAssetListMCT; // 显示资源列表的核心控件

    // 偏移量: 0xC8 / 200
    dvacore::controls::UI_StaticText* m_pExportInformationText; // 显示 "已选择/总数" 信息的文本控件
    
    // 偏移量: 0xD8 / 216
    dvacore::controls::UI_Button* m_pAddSingleAssetButton; // “添加单个资源”按钮

    // 偏移量: 0xE0 / 224
    dvacore::controls::UI_Button* m_pAddMultipleAssetsButton; // “添加多个资源”按钮
    
    // 偏移量: 0xE8 / 232
    dvacore::controls::UI_Button* m_pDeleteAssetButton; // “删除资源”按钮
    
    // 偏移量: 0xF0 / 240
    SmartExport::ExportJob* m_exportJob; // 存储当前导出任务所有参数和状态的核心对象，由 OnExportButtonClick (sub_180058CF0) 填充并使用。

    // 偏移量: 0xF8 / 248
    dvacore::controls::UI_Button* m_pExportButton; // “导出”按钮

    // --- 其他UI控件和状态 ---
    
    // 偏移量: 0x108 (264)
    dvacore::controls::UI_StaticImage* m_pSomeIcon; // 可能是某个图标

    // 偏移量: 0x110 (272)
    dvacore::controls::UI_Checkbox* m_pSelectAllCheckbox; // “全选”复选框

    // ... 其他UI控件指针 ...

    // --- 内部状态标志 ---

    // 偏移量: 0x78 / 120
    bool m_needsRefresh; // 标志位，构造时设为 true  是否需要刷新

    // 偏移量: 0x124 / 292
    bool m_isSomethingEnabled; // 另一个状态标志
    
    // 偏移量: 0x128 / 296
    int m_currentViewMode; // 当前视图模式 (1 = 网格视图, 2 = 列表视图)。由 OnCommand(sub_18002E2D0) 修改。
    
    // ... 其他内部状态变量 ...
};


    /**
     * @class AssetItem
     * @brief 代表一个可导出的资源项，是UI列表中的数据模型。
     * @note 继承自 BasicThumbnailItem 和 PreviewItem。
     */
    class AssetItem : public BasicThumbnailItem
    {
    private:
        // --- 核心数据 ---

        // 偏移量: 0x8, 0x10
        boost::shared_ptr<void> m_artHandle; // 指向AIArtHandle的智能指针

        // 偏移量: 0x20 / 32
        bool m_isSelected; // UI中复选框的勾选状态

        // 偏移量: 0x30 / 48
        ai::UnicodeString m_assetName; // 资源的名称

        // 偏移量: 0x78 / 120
        bool m_isDirty; // 状态标志位，可能表示该项的数据已变更，需要刷新预览。
        // --- 预览与图像数据 ---

        // 偏移量: 0x7C / 124  [新增细节]
        bool m_disableCustomDraw; // 标志位，用于临时禁用 OnDrawEmptyState (sub_180029B90) 的自定义绘制逻辑。

        // 偏移量: 0x98 / 152
        dvaui::drawbot::FileImageP m_thumbnailImage; // 存储生成的缩略图

        // 偏移量: 0xA8 / 168
        dvaui::drawbot::FileImageP m_statusIconImage; // 可能用于显示状态（如警告）的图标
        
        // --- 关联的导出设置 ---
        
        // 偏移量: 0xB8 / 184
        double m_scaleFactor; // 从设置中拷贝的缩放比例

        // [未知偏移量]
        std::map<double, SettingsRow*> m_exportSettings; // 存储不同导出设置的容器

            // --- 高阶指针 ---
            // 偏移量: 0x780 / 1920 [新增细节]
            void* m_appContext; // 指向一个更高级别的应用上下文或控制器对象，用于获取全局设置。

            // 偏移量: 0x4C8 / 1224 [新增细节]
            // ... 此处开始是 dvaui::ui::OS_Window 的基类成员，包含了窗口句柄等底层UI信息。

         // --- UI关联指针 ---

        // [未知偏移量]
        // 指向其在UI列表(MCT)中对应的UI节点，用于直接操作UI。
        dvacore::controls::UI_Node* m_linkedUINode;
    };



    /**
     * @struct ExportTask
     * @brief 包含一个独立文件导出所需的所有参数。
     * @note 这是由 sub_180058540 函数创建并填充的。
     * 总大小: 40 字节。
     */
    struct ExportTask
    {
        // 偏移量: 0x0 / 0
        AIArtHandle m_artHandle; // 指向要导出的具体图稿的句柄。 (8 字节)  也有可能是资源ID

        // 偏移量: 0x8 / 8
        ai::UnicodeString m_finalFileName; // 最终要生成的文件名（已包含前缀和后缀）。(24 字节)

        // 偏移量: 0x20 / 32
        int m_exportFormatEnum; // 导出格式的枚举值 (例如, 0=PNG, 1=JPG, ...)。(4 字节)   7是PDF
        
        // 偏移量: 0x24 / 36
        int m_scaleFactor; // 缩放比例的整数或浮点数表示。 (4 字节)
    }; 

struct SettingsRow{
    double scale;
    AIUnicodeString suffix;
    int fileformat;
    int isisValid; // (是否使用默认后缀)
};

typedef SettingsRow ExportSetting;

class ExportJob
{
    // --- 核心导出参数 ---

    // 偏移量: 0x0 / 0
    ai::FilePath m_destinationFolderPath; // 导出目标文件夹的路径句柄。
    
    // 偏移量: 0x10 / 16 (存在内存对齐)
    bool m_overwriteFiles; // 是否覆盖现有文件。

    // 偏移量: 0x18 / 24 (存在内存对齐)
    int m_exportMode; // 导出模式 (资源、画板等)。 // 导出模式 (0=画板, 1=资源, 2=完整文档)。

    // --- 内部数据结构 (用于组织和去重) ---

    // 偏移量: 0x20 / 32
    //std::map<FilePathHash, std::vector<ai::UnicodeString>> Key (FilePathHash): "C:\Exports\icon@2x.png" 字符串的哈希值。 Value (std::vector<ai::UnicodeString>): 一个列表，包含了所有试图写入这个相同路径的源资源名称。
    std::map<unsigned int, std::vector<ai::UnicodeString>> m_deduplicationMap; // 用于处理重名文件，由 sub_180007C80 操作。 
        
    // 偏移量: 0x30 / 48
    //数据结构: std::map<AssetID, std::vector<ExportTask>>
    //Key (AssetID): 要导出的资源或画板的ID。 Value (std::vector<ExportTask>): 一个包含了该资源所有导出任务（不同格式、尺寸）的列表。 结论: 这个 Map 的作用是按源对象（画板或资源）对导出任务进行分组，方便管理和后续处理。
    std::map<unsigned int, std::vector<ExportTask>> m_taskMap; // 用于按ID快速查找任务，由 sub_180027A60 操作。
    
    // 偏移量: 0x40 / 64
    std::vector<ExportTask> m_tasks; // 存储所有最终导出任务的核心列表，由 sub_18002A7D0 填充。

    // --- 原始UI设置 (从面板收集) ---

    // 偏移量: 0x58 / 88
    std::vector<SettingsRowData> m_artboardExportSettings; 

    // 偏移量: 0x70 / 112 
    std::vector<SettingsRowData> m_assetExportSettings;
};

struct ExportCallbackContext // v32 的类型
{
    // 当导出进度更新时调用的函数
    void (*pfnOnProgress)(AITask* task, unsigned int current, unsigned int total);

    // 当任务完成时调用的函数
    void (*pfnOnComplete)(AITask* task, int resultCode);

    // 当用户取消时调用的函数
    void (*pfnOnCancel)(AITask* task);
    
    // 指向与此任务关联的UI元素（如进度条）的指针
    void* pUserData; 
};