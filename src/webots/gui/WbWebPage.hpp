// Copyright 1996-2021 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WB_WEB_PAGE
#define WB_WEB_PAGE

#ifdef _WIN32
#include <QtWebKitWidgets/QWebPage>
#elif defined(__APPLE__) || defined(__linux__)
#include <QtWebEngineWidgets/QWebEnginePage>
#define QWebPage QWebEnginePage
#endif

class WbWebPage : public QWebPage {
  Q_OBJECT
public:
  explicit WbWebPage(QObject *parent = NULL) : QWebPage(parent) {
    connect(this, &WbWebPage::linkHovered, this, &WbWebPage::externalLinkHovered);
  }
  virtual ~WbWebPage() {}

protected:
#ifdef _WIN32
  void javaScriptConsoleMessage(const QString &message, int lineNumber, const QString &sourceUrl) override;
  bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type) override;
#else
  void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber,
                                const QString &sourceID) override;
  bool acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) override;
#endif

  WbWebPage *createWindow(QWebPage::WebWindowType type) override;

protected slots:
  void externalLinkHovered(const QString &url);

private:
  QString mHoveredLink;
};

#endif  // WB_WEB_PAGE
