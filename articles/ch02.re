= Reset CSSの特色

Reset CSSの思想は2004年に生まれ、そこから数多くのReset CSSが生まれました。
Reset CSSは年代によって思想や定義されているスタイルが若干ゃ変わっています。
この章では特に有名だと思われるReset CSSの思想を7個見ていきます。

== Hard reset

Hard resetは@<list>{hard-reset}のように書くだけの簡単なReset CSSです。

//list[hard-reset][Hard reset]{
#@mapfile(../codes/reset-css/hard-reset.css)
* {
  margin: 0;
  padding: 0;
}
#@end
//}

これが出てきたのは2004年で、おそらく最初のReset CSSだと思われます@<fn>{fight-the-power-default}。
なお公式ではHard resetと名乗っていません。Hard resetという名称は「A Comprehensive Guide to CSS Resets@<fn>{a-comprehensive-guide-to-css-resets}」という記事で出てきました。
自分は2004年当時Webサイトを作っていなかったため、当時の状況はよく分からないので次の段落は憶測を含みます。
#@# prh:disable
//footnote[fight-the-power-default][https://web.archive.org/web/20150905184045/http://leftjustified.net/journal/2004/10/07/css-negotiation/]
//footnote[a-comprehensive-guide-to-css-resets][http://sixrevisions.com/css/a-comprehensive-guide-to-css-resets/]

このHard resetが発表された当時、ブラウザ間で@<code>{margin}や@<code>{padding}の指定に差があることに対し大きな関心を持っていたようです。
そのため、全称セレクタで@<code>{margin}と@<code>{padding}を@<code>{0}にすることで、ブラウザによって@<code>{margin}や@<code>{padding}の指定に差があることを無かったことにしようと試みたようです。

== Eric Meyer's Reset CSS

Eric MeyerというCSSへ対しとても貢献している人がいます。彼の功績を挙げると次のとおりです@<fn>{eric-meyer-linkedin}。

  * オライリーから出版された@<kw>{CSS: The Definitive Guide}@<fn>{css-the-definitive-guide}（日本語版は@<kw>{CSS完全ガイド}@<fn>{css-complete-guide}）を執筆
  * 上記の本以外にも多数の本を執筆@<fn>{eric-meyer-biblio}
  * css-discuss.orgの立ち上げ@<fn>{css-discuss}
  * スライドショー用のファイルフォーマット@<kw>{S5}を考案@<fn>{s5}
  * Netscape DevEdgeやCase Western Reserve University、Encyclopedia of Cleveland Historyのプロジェクトリーダーとデザイナーだった

#@# prh:disable
//footnote[eric-meyer-linkedin][https://www.linkedin.com/in/meyerweb/]
//footnote[css-the-definitive-guide][http://shop.oreilly.com/product/9780596527334.do]
//footnote[css-complete-guide][https://www.oreilly.co.jp/books/487311232X/]
//footnote[eric-meyer-biblio][https://en.wikipedia.org/wiki/Eric_A._Meyer#Bibliography]
//footnote[css-discuss][http://www.css-discuss.org/]
#@# prh:disable
//footnote[s5][https://en.wikipedia.org/wiki/S5_(file_format)]

最近ではその功績にコミュニティが敬意を払い、彼の6歳で夭折した娘の名前をCSSの色名（@<code>{beccapurple}）として追加しようと提議されました@<fn>{becca-purple}。
そして本人と夭折した娘の要望@<fn>{rebecca-purple}により@<code>{rebeccapurple}としてCSS Color Module Level 4@<fn>{css-color-module-level-4}に追加されました。
//footnote[becca-purple][https://discourse.wicg.io/t/name-663399-becca-purple-in-css4-color/225]
#@# prh:disable
//footnote[rebecca-purple][http://meyerweb.com/eric/thoughts/2014/06/19/rebeccapurple/]
//footnote[css-color-module-level-4][https://drafts.csswg.org/css-color/#named-colors]

そのEric MeyerがHard resetの問題点を指摘した上で作ったReset CSSがEric Meyer's Reset CSSです。
#@# prh:disable
Eric Meyer's Reset CSSのソースコードは@<href>{http://meyerweb.com/eric/tools/css/reset/}にあります。

Hard resetの問題点ですが、全称セレクタを使って@<code>{margin}や@<code>{padding}を@<code>{0}にするやり方は、フォーム関連の要素に対してどういった影響があるか分からないと書いてあります。
そして@<code>{margin}や@<code>{padding}を@<code>{0}にするだけでなく、一貫したフォントに関わるスタイル宣言をしたかったとも書いてあります。
そのため明示的に要素を指定して個別にリセットしていくことで、問題を解決できると思って書かれたのがEric Meyer's Reset CSSです。

== YUI 3 Reset CSS

Yahoo!が主に開発していたYUI library@<fn>{yui-deprecate}の中に含まれるReset CSSです。
//footnote[yui-deprecate][なおYUI 3はこれからメンテナンスをおこなわないというアナウンスをしています]

YUI 3 Reset CSSはhtml要素に対し@<code>{color}プロパティや@<code>{background}プロパティが指定されています。
またarticle要素やheader要素といったHTML5で追加された要素に対する指定がありません。
これはYUI 2の時代からReset CSSがほぼ更新されていないためです@<fn>{yui2-reset}。
//footnote[yui2-reset][https://github.com/yui/yui2/blob/master/src/reset/css/reset.css]

== HTML5 Docter Reset CSS

HTML5 DocterというHTML5を使った開発について発信していたWebサイトがありました。そのWebサイトで提唱されたReset CSSです。
HTML5 Docter Reset CSSのソースコードは@<href>{http://html5doctor.com/html-5-reset-stylesheet/}にあります。

HTML5 Docter Reset CSSはEric Meyer's Reset CSSのv1.0を元に作られたものです。
Eric Meyer's Reset CSSのv1.0は作られた時期が2008年2月12日なので、HTML5に関わる要素のスタイル宣言がありませんでした。
HTML5 Docter Reset CSSはそこにHTML5で追加されたarticle要素やheader要素に対するスタイル宣言を追加しています。
またins要素やmark要素、hr要素などに独自のスタイルが適用されています。

== normalize.css

normalize.cssはそれまでのReset CSSを代替するReset CSSとして出てきました。

それまでのReset CSSはブラウザが既定で指定しているスタイルを消すものでした。
normalize.cssはブラウザが指定しているスタイルで使えそうなものはそのまま残しているのが特徴です。
後述するsanitize.cssやressと違い、作者の意見が入っていない純粋にブラウザのスタイルを正規化するライブラリです@<fn>{normalize-v5}。
//footnote[normalize-v5][v5.0.0まではスタイル宣言に作者の意見が含まれていましたが、v6.0.0でそれらがすべて取り除かれました]

ソースコードにはなぜそのような指定をしたのか書かれているため、ソースコードを読むだけでも勉強になります。

== sanitize.css

normalize.cssをNicolas Gallagherとともに作ったJonathan Nealが作ったReset CSSです。
Jonathan NealはそれまでEric Meyer's Reset CSSやnormalize.cssを使っていたようですが、それらを元に大多数が書いたスタイル宣言を含んだものがsanitize.cssです。
具体的にはhtml要素に@<code>{box-sizing: border-box;}を指定して全称セレクタで@<code>{box-sizing: inherit;}を指定することです（@<list>{sanitize-html}）。
これによって特定の要素に対してwidthやheightを指定するときに、borderやpaddingの指定を気にせずwidthやheightの値を指定できます。

//list[sanitize-html][sanitize.cssのhtml要素に対する指定]{
#@mapfile(../codes/reset-css/sanitize-css/html.css)
/**
 * 1. Remove repeating backgrounds in all browsers (opinionated).
 * 2. Add box sizing inheritence in all browsers (opinionated).
 */

*,
::before,
::after {
  background-repeat: no-repeat; /* 1 */
  box-sizing: inherit; /* 2 */
}

/**
 * 1. Add border box sizing in all browsers (opinionated).
 * 2. Add the default cursor in all browsers (opinionated).
 * 3. Prevent font size adjustments after orientation changes in IE and iOS.
 */

html {
  box-sizing: border-box; /* 1 */
  cursor: default; /* 2 */
  -ms-text-size-adjust: 100%; /* 3 */
  -webkit-text-size-adjust: 100%; /* 3 */
}
#@end
//}

== ress

最後は@<kw>{A modern CSS reset}と称するressです。
ressはnormalize.cssの指定を受け継ぎつつ、Hard resetのようにすべての@<code>{margin}や@<code>{padding}を@<code>{0}にしています。
またsanitize.cssと同じくすべての要素に対して@<code>{box-sizing: border-box;}を指定しています。
フォームに関連する要素についても@<kw>{A modern CSS reset}と称しているとおり、大胆にユーザーエージェントスタイルシートの指定をリセットしています。
