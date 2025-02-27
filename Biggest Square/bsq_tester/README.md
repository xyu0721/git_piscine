# BSQ Tester Package

42schoolのBSQプロジェクト用テストパッケージ（拡張版）

## 製作者
Rohoman Shahin (rshahino@student.42tokyo.jp)

## パッケージの内容

```
bsq_tester/
├── README.md          # このファイル
├── bsq_tester.sh      # テストスクリプト
├── docs/
│   └── README.md      # 詳細な使用方法
└── example_maps/      # サンプルマップ
    ├── basic.txt      # 基本テストケース
    ├── error.txt      # エラーケース
    ├── large.txt      # 大規模マップ
    └── huge.txt       # 超大規模マップ
```

## 機能一覧

1. 基本機能テスト
   - 3x3の基本マップ
   - 障害物のあるマップ
   - 最小サイズ（1x1）のマップ

2. エラー処理テスト
   - 無効な最初の行
   - 異なる行の長さ
   - 無効な文字
   - 空ファイル
   - 最初の行の欠落
   - 無効なサイズ（0や負数）

3. エッジケーステスト
   - 全て障害物のマップ
   - 単一の障害物
   - 境界ケース

4. 特殊ケーステスト
   - マップ前の空行
   - マップ中の空行
   - マップ後の空行
   - 数字を使用したマップ文字
   - タブや制御文字などの非表示文字
   - 同じ文字を使用したマップ文字
   - 最終行に改行がないケース

5. 標準入力テスト
   - 基本的な入力
   - 障害物のある入力
   - 無効な入力

6. 複数ファイルテスト
   - 複数マップの連続処理

7. パフォーマンステスト
   - 中規模マップ (50x50) - 2秒以内
   - 大規模マップ (100x100) - 5秒以内
   - 超大規模マップ (200x200) - 10秒以内

8. メモリリークチェック
   - Valgrindによる完全なメモリチェック
   - 詳細なリーク情報の表示

## クイックスタート

1. このディレクトリ全体をダウンロード

2. BSQプロジェクトのディレクトリに移動：
```bash
cd /path/to/your/bsq/project
```

3. プロジェクトをコンパイル：
```bash
# プロジェクトをコンパイル
make re

# bsqプログラムに実行権限があることを確認
ls -l bsq
# 権限がない場合は付与
chmod +x bsq
```

4. テストパッケージをコピー：
```bash
cp -r /path/to/bsq_tester .
```

5. テスターの権限を設定：
```bash
# ディレクトリの権限を設定
chmod 755 bsq_tester
chmod 755 bsq_tester/example_maps
chmod 755 bsq_tester/docs

# スクリプトに実行権限を付与
chmod +x bsq_tester/bsq_tester.sh

# テストマップファイルの読み取り権限を確認
chmod 644 bsq_tester/example_maps/*
```

6. テストを実行：

基本的なテスト：
```bash
./bsq_tester/bsq_tester.sh
```

メモリリークチェック付きテスト：
```bash
./bsq_tester/bsq_tester.sh -m
```

詳細な出力付きテスト：
```bash
./bsq_tester/bsq_tester.sh -v
```

全オプション使用：
```bash
./bsq_tester/bsq_tester.sh -p bsq -d test_maps -v -m
```

## オプション一覧

| オプション | 説明 |
|------------|------|
| -p, --program | プログラム名を指定（デフォルト: bsq） |
| -d, --dir | テストディレクトリを指定（デフォルト: test_maps） |
| -v, --verbose | 詳細な出力を有効化 |
| -m, --memory | Valgrindによるメモリリークチェックを有効化 |
| -h, --help | ヘルプメッセージを表示 |

## トラブルシューティング

### "Error: Program './bsq' not found or not executable" が出る場合

1. bsqプログラムが存在するか確認：
```bash
ls -l bsq
```

2. 存在しない場合は、コンパイル：
```bash
make re
```

3. 実行権限を付与：
```bash
chmod +x bsq
```

### "Error: valgrind is not installed" が出る場合

Valgrindをインストールしてください：

macOS:
```bash
brew install valgrind
```

Ubuntu/Debian:
```bash
sudo apt-get install valgrind
```

CentOS/RHEL:
```bash
sudo yum install valgrind
```

### Permission Denied エラーが出る場合

以下のコマンドで権限を修正してください：

```bash
# ディレクトリの権限を設定
chmod 755 bsq_tester
chmod 755 bsq_tester/example_maps
chmod 755 bsq_tester/docs

# スクリプトに実行権限を付与
chmod +x bsq_tester/bsq_tester.sh

# テストマップファイルの読み取り権限を確認
chmod 644 bsq_tester/example_maps/*
```

## 詳細な使用方法

詳細な使用方法は `docs/README.md` を参照してください。

## サンプルマップ

`example_maps` ディレクトリには、テスト用のサンプルマップが含まれています：

- `basic.txt`: 基本的なテストケース
- `error.txt`: エラーケースのテスト
- `large.txt`: パフォーマンステスト用の大きなマップ（100x100）
- `huge.txt`: パフォーマンステスト用の超大規模マップ（200x200）

## パフォーマンス基準

| マップサイズ | 制限時間 |
|------------|---------|
| 50x50 | 2秒以内 |
| 100x100 | 5秒以内 |
| 200x200 | 10秒以内 |

## 注意事項

1. このテスターは非公式のものです
2. 42schoolの評価基準は変更される可能性があります
3. このテスターをパスしても、実際の評価でパスすることを保証するものではありません
4. テスト実行前に必ずプロジェクトが正しくコンパイルされていることを確認してください
5. メモリリークチェックはValgrindがインストールされている環境でのみ使用可能です
6. パフォーマンステストの制限時間は環境によって調整が必要な場合があります

## テストケース詳細

### 基本機能テスト
- 3x3の基本マップ: 全て空きマスのマップで最大の正方形を見つける
- 障害物のあるマップ: 障害物を避けて最大の正方形を見つける
- 最小サイズ: 1x1のマップで正しく動作することを確認

### エラー処理テスト
- 無効な最初の行: フォーマットが正しくない場合のエラー処理
- 異なる行の長さ: 行の長さが一致しない場合のエラー処理
- 無効な文字: 指定された文字以外が使用された場合のエラー処理
- 空ファイル: ファイルが空の場合のエラー処理
- 最初の行の欠落: マップの情報行が欠落している場合のエラー処理
- 無効なサイズ: サイズが0以下の場合のエラー処理

### 特殊ケーステスト
1. 空行テスト
   - マップ前に空行がある場合
   - マップ中に空行がある場合
   - マップ後に空行がある場合

2. 文字テスト
   - empty, obstacle, fullに数字を使用
   - empty, obstacle, fullに非表示文字を使用
   - empty, obstacle, fullに同じ文字を使用

3. フォーマットテスト
   - 最終行に改行がないケース
   - タブ文字を含むケース
   - 制御文字を含むケース 