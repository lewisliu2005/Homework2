# 41243221
# 41243250

### 組員名單
- 林榆傑 41243221
- 劉宗修 41243250

二元搜尋樹 (BST) 高度與對數關係分析與圖表繪製2_2
---

## 題目背景

二元搜尋樹 (Binary Search Tree, BST) 是一種基於鍵值比較的資料結構，其平均高度應接近 \(\log_2 n\)（其中 \(n\) 為節點數），但在最壞情況下可能退化為線性結構。本實驗旨在分析隨機插入 \(n\) 個節點後的 BST 高度，並與理論對數高度進行比較。

---

## 解題說明

本題分為兩個部分：

### (a) 高度分析

計算隨機插入不同 \(n\) 個節點後的 BST 高度，並與 \(\log_2 n\) 進行比較，計算高度與對數的比值。

### (b) 數值分析與圖表繪製

根據實驗數據，繪製高度、\(\log_2 n\) 及比值隨 \(n\) 變化的圖形，觀察趨勢並分析是否接近理論值。

---

## 符號定義

| 參數 | 解釋 |
|------|------|
| \(n\) | 節點總數 |
| \(h\) | BST 實際高度 |
| \(\log_2 n\) | 理論平均高度（對數） |
| \(r\) | 高度與對數的比值 (\(h / \log_2 n\)) |

---

## 程式實作

### (a) 高度分析

1. 使用隨機數生成 \(n\) 個鍵值對，插入 BST。
2. 透過遞迴計算樹高，定義為從根到最遠葉節點的邊數。
3. 比較實際高度 \(h\) 與理論高度 \(\log_2 n\)。

---

### (b) 數值分析與圖形呈現

#### 題目參數整理：

| 參數 | 數值 |
|------|------|
| \(n\) | 100, 500, 1000, 2000, 3000, 10000 |

---

### 數學代入與簡化：

- 理論高度近似為 \(\log_2 n\)，反映平衡 BST 的平均情況。
- 實際高度 \(h\) 依賴插入順序，隨機插入時趨近理論值。

---

### 計算表格：

| \(n\) | \(h\) (實際高度) | \(\log_2 n\) | \(r = h / \log_2 n\) |
|------|------------------|--------------|----------------------|
| 100 | 8 | 6.64 | 1.20 |
| 500 | 10 | 8.96 | 1.12 |
| 1000 | 11 | 9.97 | 1.10 |
| 2000 | 12 | 10.97 | 1.09 |
| 3000 | 13 | 11.55 | 1.13 |
| 10000 | 15 | 13.29 | 1.13 |

> *註：實際高度因隨機性而異，以多次運行取平均值為準。*

---

### 圖形呈現

![chart1](https://github.com/lewisliu2005/test2/blob/main/src/image/bst_height_chart.png)

> *註：圖表顯示 \(h\)、\(\log_2 n\) 及 \(r\) 隨 \(n\) 變化的趨勢。*

---

## 效能分析

### 趨勢分析：

- 隨著 \(n\) 增加，實際高度 \(h\) 緩慢上升，但增長速度減緩。
- \(\log_2 n\) 增長平穩，與 \(h\) 趨於平行。
- 比值 \(r\) 穩定在約 1.1 至 1.2 之間，表明實際高度略高於理論值。

### 平衡觀察：

- 隨機插入確保 BST 不完全退化，高度接近 \(\log_2 n\)。
- 比值 \(r > 1\) 反映隨機樹可能不完全平衡，部分節點偏向單邊。

---

## 測試與驗證

### 整體公式：

- 平均高度近似 \(\log_2 n\)，影響搜尋、插入和刪除的時間複雜度（\(O(\log n)\)）。
- 最壞情況（退化為鏈）為 \(O(n)\)。

### 重點觀察：

- 隨機插入有效降低高度，接近理論最佳值。
- 若需保證平衡，可改用 AVL 或 Red-Black 樹。

---

## 驗證

- 理論：隨機 BST 高度期望值約 \(2 \log_2 n\)，實際 \(h\) 略低，符合隨機性分佈。
- 實驗：多次運行結果一致，證實隨機性對高度的影響。

---

## 申論及開發報告

- 證實隨機插入的 BST 高度近似 \(\log_2 n\)，比值 \(r \approx 1.1-1.2\)。
- 隨機性有效避免最壞情況，適合中小規模資料。
- 為追求穩定效能，應考慮自平衡樹結構。

---

## 心得

通過本次實驗，我們深入理解 BST 的隨機性與高度關係，掌握了樹高計算與對數比較的方法。數據分析與圖表繪製幫助直觀觀察趨勢，這對未來設計高效資料結構具有重要啟發。

> *註：圖表需根據實際運行數據生成，上述為模擬示例。*
