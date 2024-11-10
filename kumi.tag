<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.9.6" doxygen_gitid="4586b5cfaa3d46d51f6a51882951d15644c49edf">
  <compound kind="struct">
    <name>kumi::as_tuple</name>
    <filename>structkumi_1_1as__tuple.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::element</name>
    <filename>structkumi_1_1element.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::index_t</name>
    <filename>structkumi_1_1index__t.html</filename>
    <templarg>std::size_t N</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator std::size_t</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>a4dd6abb0a1663aa1f355ee416ee3083e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>value</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>ab659f5d62c79ae49fe525448df86765b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::is_homogeneous</name>
    <filename>structkumi_1_1is__homogeneous.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::is_product_type</name>
    <filename>structkumi_1_1is__product__type.html</filename>
    <templarg>typename T</templarg>
    <templarg>typename Enable</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::member</name>
    <filename>structkumi_1_1member.html</filename>
    <templarg>std::size_t I</templarg>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::size</name>
    <filename>structkumi_1_1size.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::tuple</name>
    <filename>structkumi_1_1tuple.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1tuple_a4dbc1f9afc38da2733510424098948ff.html</anchorfile>
      <anchor>a4dbc1f9afc38da2733510424098948ff</anchor>
      <arglist>(Function &amp;&amp;f) const &amp;noexcept(noexcept(kumi::apply(static_cast&lt; decltype(f) &amp;&amp; &gt;(f), *this)))</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad876de41968b5ee06bccf70695592f54</anchor>
      <arglist>(tuple&lt; Us... &gt; &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple_a4fd625da2ba811927789a6c838330144.html</anchorfile>
      <anchor>a4fd625da2ba811927789a6c838330144</anchor>
      <arglist>(tuple&lt; Us... &gt; const &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_add9b4c557357c1778591a76e14f57c1f.html</anchorfile>
      <anchor>add9b4c557357c1778591a76e14f57c1f</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a3a0c21d67f0ed1df6abfb8da20b05870</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a91af8e233b4f2b7156078dfaf1237ee8</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7822474c1e0f596d5929ab0d46da4623</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a9eb39bbd2e8e1d97a31047113eb5f55e.html</anchorfile>
      <anchor>a9eb39bbd2e8e1d97a31047113eb5f55e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2d1ce1c8d2628bd8cc3fef2e760d6205</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1528baca5725019f4ef52b2aadd919e6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf6739a069131e315597688e5b3cf5df9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>tuple</name>
      <anchorfile>group__tuple_ga446a0931c46caf9cfb2f3977a2492624.html</anchorfile>
      <anchor>ga446a0931c46caf9cfb2f3977a2492624</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;... &gt;</type>
      <name>tie</name>
      <anchorfile>group__tuple_ga3b5a893567431a62dce006d10f23854b.html</anchorfile>
      <anchor>ga3b5a893567431a62dce006d10f23854b</anchor>
      <arglist>(Ts &amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;&amp;... &gt;</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple_ga2e59034f40a923f671b72a88cc1ed045.html</anchorfile>
      <anchor>ga2e59034f40a923f671b72a88cc1ed045</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga7a585805b36bec6b2c275b6f2ced67fe.html</anchorfile>
      <anchor>ga7a585805b36bec6b2c275b6f2ced67fe</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga8c39a63412ff38a02ffd6bc2394581ca.html</anchorfile>
      <anchor>ga8c39a63412ff38a02ffd6bc2394581ca</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple_add9b4c557357c1778591a76e14f57c1f.html</anchorfile>
      <anchor>add9b4c557357c1778591a76e14f57c1f</anchor>
      <arglist>(index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a3a0c21d67f0ed1df6abfb8da20b05870</anchor>
      <arglist>(index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a91af8e233b4f2b7156078dfaf1237ee8</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7822474c1e0f596d5929ab0d46da4623</anchor>
      <arglist>(index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cast</name>
      <anchorfile>structkumi_1_1tuple_a9eb39bbd2e8e1d97a31047113eb5f55e.html</anchorfile>
      <anchor>a9eb39bbd2e8e1d97a31047113eb5f55e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2d1ce1c8d2628bd8cc3fef2e760d6205</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a1528baca5725019f4ef52b2aadd919e6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator==</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf074114f7e38446c5e298e6701e8a54b</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac0b978b3e13c057400e145cc8ac174b0</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac139a2d53851de1cad516a46c5f5b890</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gab8a56dde0a34774be10c93e2ead36db8</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac63791b4319477192bf982cb834e2985</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>tuple</name>
      <anchorfile>group__tuple_ga446a0931c46caf9cfb2f3977a2492624.html</anchorfile>
      <anchor>ga446a0931c46caf9cfb2f3977a2492624</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;... &gt;</type>
      <name>tie</name>
      <anchorfile>group__tuple_ga3b5a893567431a62dce006d10f23854b.html</anchorfile>
      <anchor>ga3b5a893567431a62dce006d10f23854b</anchor>
      <arglist>(Ts &amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;&amp;... &gt;</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__tuple_ga2e59034f40a923f671b72a88cc1ed045.html</anchorfile>
      <anchor>ga2e59034f40a923f671b72a88cc1ed045</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</type>
      <name>make_tuple</name>
      <anchorfile>group__tuple_ga7a585805b36bec6b2c275b6f2ced67fe.html</anchorfile>
      <anchor>ga7a585805b36bec6b2c275b6f2ced67fe</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>to_ref</name>
      <anchorfile>group__tuple_ga8c39a63412ff38a02ffd6bc2394581ca.html</anchorfile>
      <anchor>ga8c39a63412ff38a02ffd6bc2394581ca</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="concept">
    <name>kumi::equality_comparable</name>
    <filename>conceptkumi_1_1equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::homogeneous_product_type</name>
    <filename>conceptkumi_1_1homogeneous__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::non_empty_product_type</name>
    <filename>conceptkumi_1_1non__empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::product_type</name>
    <filename>conceptkumi_1_1product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::sized_product_type</name>
    <filename>conceptkumi_1_1sized__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::sized_product_type_or_more</name>
    <filename>conceptkumi_1_1sized__product__type__or__more.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::std_tuple_compatible</name>
    <filename>conceptkumi_1_1std__tuple__compatible.html</filename>
  </compound>
  <compound kind="namespace">
    <name>kumi</name>
    <filename>namespacekumi.html</filename>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::index_t</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::size</class>
    <class kind="class">kumi::tuple</class>
    <concept>kumi::std_tuple_compatible</concept>
    <concept>kumi::product_type</concept>
    <concept>kumi::sized_product_type</concept>
    <concept>kumi::sized_product_type_or_more</concept>
    <concept>kumi::non_empty_product_type</concept>
    <concept>kumi::homogeneous_product_type</concept>
    <concept>kumi::equality_comparable</concept>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_of</name>
      <anchorfile>group__queries_ga40bf2969c7b8a6fdf5c8eecf6a1436a2.html</anchorfile>
      <anchor>ga40bf2969c7b8a6fdf5c8eecf6a1436a2</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>all_of</name>
      <anchorfile>group__queries_ga262f5e099c46aacaf7b117033b22b7e8.html</anchorfile>
      <anchor>ga262f5e099c46aacaf7b117033b22b7e8</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_gafdfb5550011004d4306d9c8a67586d66.html</anchorfile>
      <anchor>gafdfb5550011004d4306d9c8a67586d66</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>any_of</name>
      <anchorfile>group__queries_ga8d7de5c00a3b6cfc1fc4a8ed3bea53b2.html</anchorfile>
      <anchor>ga8d7de5c00a3b6cfc1fc4a8ed3bea53b2</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>apply</name>
      <anchorfile>group__transforms_ga612ed868d8ee0ecabcdaa0d6a7c116fb.html</anchorfile>
      <anchor>ga612ed868d8ee0ecabcdaa0d6a7c116fb</anchor>
      <arglist>(Function &amp;&amp;f, Tuple &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, Tuple &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD auto</type>
      <name>as_flat_ptr</name>
      <anchorfile>group__generators_ga592ec585976cc6544c799402a5c4ef1c.html</anchorfile>
      <anchor>ga592ec585976cc6544c799402a5c4ef1c</anchor>
      <arglist>(Tuple &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>back</name>
      <anchorfile>group__utility_ga1818d1862531a044583a68d70e46723b.html</anchorfile>
      <anchor>ga1818d1862531a044583a68d70e46723b</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga086ae741edfc80131295802c31e08af9.html</anchorfile>
      <anchor>ga086ae741edfc80131295802c31e08af9</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_and</name>
      <anchorfile>group__reductions_ga491ecadaaedfe84e927302683f108625.html</anchorfile>
      <anchor>ga491ecadaaedfe84e927302683f108625</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_gad66c3ad56b3536942c960c2cad1fabcf.html</anchorfile>
      <anchor>gad66c3ad56b3536942c960c2cad1fabcf</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bit_or</name>
      <anchorfile>group__reductions_ga74ca2a5811c0ba2e5b0c07f6aea15d90.html</anchorfile>
      <anchor>ga74ca2a5811c0ba2e5b0c07f6aea15d90</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>cartesian_product</name>
      <anchorfile>group__generators_ga1a62cf631e1471cf1da2b2f7ae2120b0.html</anchorfile>
      <anchor>ga1a62cf631e1471cf1da2b2f7ae2120b0</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>cat</name>
      <anchorfile>group__generators_ga48221d9b00705f2cb90230f691334f72.html</anchorfile>
      <anchor>ga48221d9b00705f2cb90230f691334f72</anchor>
      <arglist>(Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr std::size_t</type>
      <name>count</name>
      <anchorfile>group__queries_ga34b674518c68e4cced2155d8da86f793.html</anchorfile>
      <anchor>ga34b674518c68e4cced2155d8da86f793</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>count_if</name>
      <anchorfile>group__queries_ga6e626baf1ad5f29106db9428aa55f85d.html</anchorfile>
      <anchor>ga6e626baf1ad5f29106db9428aa55f85d</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>extract</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a9d1de1fea414717f4b1fb44c62ead1b3</anchor>
      <arglist>(Tuple const &amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>extract</name>
      <anchorfile>group__generators_ga9d67ce72cbaa5c87a582cc6b913ee8e3.html</anchorfile>
      <anchor>ga9d67ce72cbaa5c87a582cc6b913ee8e3</anchor>
      <arglist>(Tuple const &amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten</name>
      <anchorfile>group__generators_gaeefb24a9d75d8753477bae03bc6e205c.html</anchorfile>
      <anchor>gaeefb24a9d75d8753477bae03bc6e205c</anchor>
      <arglist>(Tuple const &amp;ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a16916472ef4928dc9ed24a99cc4da97f</anchor>
      <arglist>(Tuple &amp;&amp;ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>flatten_all</name>
      <anchorfile>group__generators_ga152d59e645273cd17b762b839db88dbb.html</anchorfile>
      <anchor>ga152d59e645273cd17b762b839db88dbb</anchor>
      <arglist>(Tuple &amp;&amp;ts, Func &amp;&amp;f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_gaed0714239b395a2ac14d3a6a3ec3f44c.html</anchorfile>
      <anchor>gaed0714239b395a2ac14d3a6a3ec3f44c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_left</name>
      <anchorfile>group__reductions_gaf5c5a77520eb5db15716f55fdb413579.html</anchorfile>
      <anchor>gaf5c5a77520eb5db15716f55fdb413579</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_ga20c7d2a3b7e7044f95ec352e64cd1b27.html</anchorfile>
      <anchor>ga20c7d2a3b7e7044f95ec352e64cd1b27</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>fold_right</name>
      <anchorfile>group__reductions_gaa2bdd088d82f635a5c52c6dd5bdeaaf2.html</anchorfile>
      <anchor>gaa2bdd088d82f635a5c52c6dd5bdeaaf2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each</name>
      <anchorfile>group__transforms_ga757e3791ec5e2353fa1f52ec6dafdcb1.html</anchorfile>
      <anchor>ga757e3791ec5e2353fa1f52ec6dafdcb1</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>for_each_index</name>
      <anchorfile>group__transforms_gab74a95670c1baa3ec7e7905d42a5f216.html</anchorfile>
      <anchor>gab74a95670c1baa3ec7e7905d42a5f216</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>from_tuple</name>
      <anchorfile>group__utility_gad8e73ef5a6e05c2ae2db0bcfa860de48.html</anchorfile>
      <anchor>gad8e73ef5a6e05c2ae2db0bcfa860de48</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>front</name>
      <anchorfile>group__utility_ga0fc57b54b71d2726c24df5ddbab97bd3.html</anchorfile>
      <anchor>ga0fc57b54b71d2726c24df5ddbab97bd3</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>generate</name>
      <anchorfile>group__generators_ga148569641f64ccb586aaa65ccb6d1ae6.html</anchorfile>
      <anchor>ga148569641f64ccb586aaa65ccb6d1ae6</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a5b5aff48796b3da4d80700c5dfcb68d6</anchor>
      <arglist>(S1 const &amp;s1, S2 const &amp;s2, T init) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>inner_product</name>
      <anchorfile>group__reductions_gaf5877256b018bb540f28cc0f7ddd26cb.html</anchorfile>
      <anchor>gaf5877256b018bb540f28cc0f7ddd26cb</anchor>
      <arglist>(S1 const &amp;s1, S2 const &amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>locate</name>
      <anchorfile>group__queries_ga5b528cf4282e026dc1efb52ab546bf81.html</anchorfile>
      <anchor>ga5b528cf4282e026dc1efb52ab546bf81</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map</name>
      <anchorfile>group__transforms_ga8a4e424cfc506fb8fd2939ebe24382ce.html</anchorfile>
      <anchor>ga8a4e424cfc506fb8fd2939ebe24382ce</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>map_index</name>
      <anchorfile>group__transforms_ga24c0a7632bd20e448dd7ac2d18e1168c.html</anchorfile>
      <anchor>ga24c0a7632bd20e448dd7ac2d18e1168c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_ga7cb6c22dc5a7e603a051591859e8ccee.html</anchorfile>
      <anchor>ga7cb6c22dc5a7e603a051591859e8ccee</anchor>
      <arglist>(T const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__reductions_ga5e11e6a667c808afc39641a25d5190c5.html</anchorfile>
      <anchor>ga5e11e6a667c808afc39641a25d5190c5</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>max_flat</name>
      <anchorfile>group__reductions_ga7398e59d84beec31000bf3d6bbe28ec6.html</anchorfile>
      <anchor>ga7398e59d84beec31000bf3d6bbe28ec6</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_ga339bdf2876d5e82e73f5737f913e1eae.html</anchorfile>
      <anchor>ga339bdf2876d5e82e73f5737f913e1eae</anchor>
      <arglist>(T const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__reductions_ga8e5f2dc53e07cd34f0a0d578c89db4c5.html</anchorfile>
      <anchor>ga8e5f2dc53e07cd34f0a0d578c89db4c5</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>min_flat</name>
      <anchorfile>group__reductions_ga53ac4cb775845cdae5c895cd5098e0c8.html</anchorfile>
      <anchor>ga53ac4cb775845cdae5c895cd5098e0c8</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_ga5efc50044b53b7bb4c17ba3a521c289a.html</anchorfile>
      <anchor>ga5efc50044b53b7bb4c17ba3a521c289a</anchor>
      <arglist>(Tuple const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>none_of</name>
      <anchorfile>group__queries_gaad40e49ccd63af4301c797b29b371394.html</anchorfile>
      <anchor>gaad40e49ccd63af4301c797b29b371394</anchor>
      <arglist>(Tuple const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>partition</name>
      <anchorfile>group__generators_ga247e68735773ce448a9fc25f02d7dca0.html</anchorfile>
      <anchor>ga247e68735773ce448a9fc25f02d7dca0</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_back</name>
      <anchorfile>group__generators_ga02ec85698dbf8f7b5ccdcb2e1d09cb32.html</anchorfile>
      <anchor>ga02ec85698dbf8f7b5ccdcb2e1d09cb32</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>pop_front</name>
      <anchorfile>group__generators_ga765ba6427ebaa29a76e435fabd799a6d.html</anchorfile>
      <anchor>ga765ba6427ebaa29a76e435fabd799a6d</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga8f26159ad4592d129baf258026910f98.html</anchorfile>
      <anchor>ga8f26159ad4592d129baf258026910f98</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>prod</name>
      <anchorfile>group__reductions_ga19f0d8f804838dcc33eb3456358bf96f.html</anchorfile>
      <anchor>ga19f0d8f804838dcc33eb3456358bf96f</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_back</name>
      <anchorfile>group__generators_ga7eb7a6fd2d7e8ebab521c951b0b4f2ac.html</anchorfile>
      <anchor>ga7eb7a6fd2d7e8ebab521c951b0b4f2ac</anchor>
      <arglist>(Tuple const &amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>push_front</name>
      <anchorfile>group__generators_ga9ee421ee66f4eec5b041be32014b13bc.html</anchorfile>
      <anchor>ga9ee421ee66f4eec5b041be32014b13bc</anchor>
      <arglist>(Tuple const &amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>reorder</name>
      <anchorfile>group__generators_ga6a0d19d47ea70b25b1ad09ea9202f592.html</anchorfile>
      <anchor>ga6a0d19d47ea70b25b1ad09ea9202f592</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>reverse</name>
      <anchorfile>group__generators_ga49abf24bfdc3e6c8707cd321d9015212.html</anchorfile>
      <anchor>ga49abf24bfdc3e6c8707cd321d9015212</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>split</name>
      <anchorfile>group__generators_ga502cb965978ae8df41a0605a129577bf.html</anchorfile>
      <anchor>ga502cb965978ae8df41a0605a129577bf</anchor>
      <arglist>(Tuple const &amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_gab24f978a257b3974311f19306f211d87.html</anchorfile>
      <anchor>gab24f978a257b3974311f19306f211d87</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>sum</name>
      <anchorfile>group__reductions_gafbf960e6940d260757abde26e985c878.html</anchorfile>
      <anchor>gafbf960e6940d260757abde26e985c878</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>to_tuple</name>
      <anchorfile>group__utility_gae6de7cdd99f5e217028b93d4bcf3de52.html</anchorfile>
      <anchor>gae6de7cdd99f5e217028b93d4bcf3de52</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>transpose</name>
      <anchorfile>group__generators_ga1a15bc7904a51c4854d17c177b88027a.html</anchorfile>
      <anchor>ga1a15bc7904a51c4854d17c177b88027a</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>zip</name>
      <anchorfile>group__generators_gae8df7fc3aefbc6551f09c4ce64f6f82b.html</anchorfile>
      <anchor>gae8df7fc3aefbc6551f09c4ce64f6f82b</anchor>
      <arglist>(T0 const &amp;t0, Ts const &amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>afa07a9995292cf82075b2f6855543268</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a4629daa6992aeb4cb3b0241c07eb3ba1</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a353f45a2d30c3d0b1c80f7f794360326</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="variable">
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>afa07a9995292cf82075b2f6855543268</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a4629daa6992aeb4cb3b0241c07eb3ba1</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a353f45a2d30c3d0b1c80f7f794360326</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>literals</name>
    <filename>namespaceliterals.html</filename>
  </compound>
  <compound kind="group">
    <name>utility</name>
    <title>Helper Types and Functions</title>
    <filename>group__utility.html</filename>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="struct">kumi::index_t</class>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>kumi::back</name>
      <anchorfile>group__utility_ga1818d1862531a044583a68d70e46723b.html</anchorfile>
      <anchor>ga1818d1862531a044583a68d70e46723b</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::from_tuple</name>
      <anchorfile>group__utility_gad8e73ef5a6e05c2ae2db0bcfa860de48.html</anchorfile>
      <anchor>gad8e73ef5a6e05c2ae2db0bcfa860de48</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)</type>
      <name>kumi::front</name>
      <anchorfile>group__utility_ga0fc57b54b71d2726c24df5ddbab97bd3.html</anchorfile>
      <anchor>ga0fc57b54b71d2726c24df5ddbab97bd3</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_c</name>
      <anchorfile>group__utility_ga60825dffaa5ee2c50e1d1a24057bdcf1.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::predicate</name>
      <anchorfile>group__utility_ga9c8c29e8a2f4f5e8a663200559fdc983.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::to_tuple</name>
      <anchorfile>group__utility_gae6de7cdd99f5e217028b93d4bcf3de52.html</anchorfile>
      <anchor>gae6de7cdd99f5e217028b93d4bcf3de52</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="variable">
      <type>constexpr index_t&lt; N &gt; const</type>
      <name>kumi::index</name>
      <anchorfile>group__utility.html</anchorfile>
      <anchor>ga32a67892e5dbfb93a2292959a5a029d0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>algorithm</name>
    <title>Tuple Algorithms</title>
    <filename>group__algorithm.html</filename>
    <subgroup>reductions</subgroup>
    <subgroup>generators</subgroup>
    <subgroup>queries</subgroup>
    <subgroup>transforms</subgroup>
  </compound>
  <compound kind="group">
    <name>reductions</name>
    <title>Tuple Generalized Reductions</title>
    <filename>group__reductions.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga086ae741edfc80131295802c31e08af9.html</anchorfile>
      <anchor>ga086ae741edfc80131295802c31e08af9</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__reductions_ga491ecadaaedfe84e927302683f108625.html</anchorfile>
      <anchor>ga491ecadaaedfe84e927302683f108625</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_gad66c3ad56b3536942c960c2cad1fabcf.html</anchorfile>
      <anchor>gad66c3ad56b3536942c960c2cad1fabcf</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__reductions_ga74ca2a5811c0ba2e5b0c07f6aea15d90.html</anchorfile>
      <anchor>ga74ca2a5811c0ba2e5b0c07f6aea15d90</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_gaed0714239b395a2ac14d3a6a3ec3f44c.html</anchorfile>
      <anchor>gaed0714239b395a2ac14d3a6a3ec3f44c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__reductions_gaf5c5a77520eb5db15716f55fdb413579.html</anchorfile>
      <anchor>gaf5c5a77520eb5db15716f55fdb413579</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_ga20c7d2a3b7e7044f95ec352e64cd1b27.html</anchorfile>
      <anchor>ga20c7d2a3b7e7044f95ec352e64cd1b27</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__reductions_gaa2bdd088d82f635a5c52c6dd5bdeaaf2.html</anchorfile>
      <anchor>gaa2bdd088d82f635a5c52c6dd5bdeaaf2</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::inner_product</name>
      <anchorfile>group__reductions_gaf5877256b018bb540f28cc0f7ddd26cb.html</anchorfile>
      <anchor>gaf5877256b018bb540f28cc0f7ddd26cb</anchor>
      <arglist>(S1 const &amp;s1, S2 const &amp;s2, T init, Sum sum, Prod prod) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_ga7cb6c22dc5a7e603a051591859e8ccee.html</anchorfile>
      <anchor>ga7cb6c22dc5a7e603a051591859e8ccee</anchor>
      <arglist>(T const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max</name>
      <anchorfile>group__reductions_ga5e11e6a667c808afc39641a25d5190c5.html</anchorfile>
      <anchor>ga5e11e6a667c808afc39641a25d5190c5</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::max_flat</name>
      <anchorfile>group__reductions_ga7398e59d84beec31000bf3d6bbe28ec6.html</anchorfile>
      <anchor>ga7398e59d84beec31000bf3d6bbe28ec6</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_ga339bdf2876d5e82e73f5737f913e1eae.html</anchorfile>
      <anchor>ga339bdf2876d5e82e73f5737f913e1eae</anchor>
      <arglist>(T const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min</name>
      <anchorfile>group__reductions_ga8e5f2dc53e07cd34f0a0d578c89db4c5.html</anchorfile>
      <anchor>ga8e5f2dc53e07cd34f0a0d578c89db4c5</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::min_flat</name>
      <anchorfile>group__reductions_ga53ac4cb775845cdae5c895cd5098e0c8.html</anchorfile>
      <anchor>ga53ac4cb775845cdae5c895cd5098e0c8</anchor>
      <arglist>(T const &amp;t, F f) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga8f26159ad4592d129baf258026910f98.html</anchorfile>
      <anchor>ga8f26159ad4592d129baf258026910f98</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::prod</name>
      <anchorfile>group__reductions_ga19f0d8f804838dcc33eb3456358bf96f.html</anchorfile>
      <anchor>ga19f0d8f804838dcc33eb3456358bf96f</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gab24f978a257b3974311f19306f211d87.html</anchorfile>
      <anchor>gab24f978a257b3974311f19306f211d87</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::sum</name>
      <anchorfile>group__reductions_gafbf960e6940d260757abde26e985c878.html</anchorfile>
      <anchor>gafbf960e6940d260757abde26e985c878</anchor>
      <arglist>(Tuple &amp;&amp;t, Value init)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>generators</name>
    <title>Tuple Generators</title>
    <filename>group__generators.html</filename>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD auto</type>
      <name>kumi::as_flat_ptr</name>
      <anchorfile>group__generators_ga592ec585976cc6544c799402a5c4ef1c.html</anchorfile>
      <anchor>ga592ec585976cc6544c799402a5c4ef1c</anchor>
      <arglist>(Tuple &amp;&amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::cartesian_product</name>
      <anchorfile>group__generators_ga1a62cf631e1471cf1da2b2f7ae2120b0.html</anchorfile>
      <anchor>ga1a62cf631e1471cf1da2b2f7ae2120b0</anchor>
      <arglist>(Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>kumi::cat</name>
      <anchorfile>group__generators_ga48221d9b00705f2cb90230f691334f72.html</anchorfile>
      <anchor>ga48221d9b00705f2cb90230f691334f72</anchor>
      <arglist>(Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::extract</name>
      <anchorfile>group__generators_ga9d67ce72cbaa5c87a582cc6b913ee8e3.html</anchorfile>
      <anchor>ga9d67ce72cbaa5c87a582cc6b913ee8e3</anchor>
      <arglist>(Tuple const &amp;t, index_t&lt; I0 &gt; i0, index_t&lt; I1 &gt; i1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten</name>
      <anchorfile>group__generators_gaeefb24a9d75d8753477bae03bc6e205c.html</anchorfile>
      <anchor>gaeefb24a9d75d8753477bae03bc6e205c</anchor>
      <arglist>(Tuple const &amp;ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::flatten_all</name>
      <anchorfile>group__generators_ga152d59e645273cd17b762b839db88dbb.html</anchorfile>
      <anchor>ga152d59e645273cd17b762b839db88dbb</anchor>
      <arglist>(Tuple &amp;&amp;ts, Func &amp;&amp;f)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::generate</name>
      <anchorfile>group__generators_ga148569641f64ccb586aaa65ccb6d1ae6.html</anchorfile>
      <anchor>ga148569641f64ccb586aaa65ccb6d1ae6</anchor>
      <arglist>(T const &amp;v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::iota</name>
      <anchorfile>group__generators_ga19ced0b66d1e3dae7bfa60f7def6914f.html</anchorfile>
      <anchor>ga19ced0b66d1e3dae7bfa60f7def6914f</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::partition</name>
      <anchorfile>group__generators_ga247e68735773ce448a9fc25f02d7dca0.html</anchorfile>
      <anchor>ga247e68735773ce448a9fc25f02d7dca0</anchor>
      <arglist>(T &amp;&amp;tup) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_back</name>
      <anchorfile>group__generators_ga02ec85698dbf8f7b5ccdcb2e1d09cb32.html</anchorfile>
      <anchor>ga02ec85698dbf8f7b5ccdcb2e1d09cb32</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::pop_front</name>
      <anchorfile>group__generators_ga765ba6427ebaa29a76e435fabd799a6d.html</anchorfile>
      <anchor>ga765ba6427ebaa29a76e435fabd799a6d</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_back</name>
      <anchorfile>group__generators_ga7eb7a6fd2d7e8ebab521c951b0b4f2ac.html</anchorfile>
      <anchor>ga7eb7a6fd2d7e8ebab521c951b0b4f2ac</anchor>
      <arglist>(Tuple const &amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::push_front</name>
      <anchorfile>group__generators_ga9ee421ee66f4eec5b041be32014b13bc.html</anchorfile>
      <anchor>ga9ee421ee66f4eec5b041be32014b13bc</anchor>
      <arglist>(Tuple const &amp;t, T &amp;&amp;v)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>kumi::reorder</name>
      <anchorfile>group__generators_ga6a0d19d47ea70b25b1ad09ea9202f592.html</anchorfile>
      <anchor>ga6a0d19d47ea70b25b1ad09ea9202f592</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::reverse</name>
      <anchorfile>group__generators_ga49abf24bfdc3e6c8707cd321d9015212.html</anchorfile>
      <anchor>ga49abf24bfdc3e6c8707cd321d9015212</anchor>
      <arglist>(Tuple &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::split</name>
      <anchorfile>group__generators_ga502cb965978ae8df41a0605a129577bf.html</anchorfile>
      <anchor>ga502cb965978ae8df41a0605a129577bf</anchor>
      <arglist>(Tuple const &amp;t, index_t&lt; I0 &gt; i0) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::transpose</name>
      <anchorfile>group__generators_ga1a15bc7904a51c4854d17c177b88027a.html</anchorfile>
      <anchor>ga1a15bc7904a51c4854d17c177b88027a</anchor>
      <arglist>(Tuple const &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::zip</name>
      <anchorfile>group__generators_gae8df7fc3aefbc6551f09c4ce64f6f82b.html</anchorfile>
      <anchor>gae8df7fc3aefbc6551f09c4ce64f6f82b</anchor>
      <arglist>(T0 const &amp;t0, Ts const &amp;...ts)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>queries</name>
    <title>Tuple Queries</title>
    <filename>group__queries.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_ga40bf2969c7b8a6fdf5c8eecf6a1436a2.html</anchorfile>
      <anchor>ga40bf2969c7b8a6fdf5c8eecf6a1436a2</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::all_of</name>
      <anchorfile>group__queries_ga262f5e099c46aacaf7b117033b22b7e8.html</anchorfile>
      <anchor>ga262f5e099c46aacaf7b117033b22b7e8</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_gafdfb5550011004d4306d9c8a67586d66.html</anchorfile>
      <anchor>gafdfb5550011004d4306d9c8a67586d66</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::any_of</name>
      <anchorfile>group__queries_ga8d7de5c00a3b6cfc1fc4a8ed3bea53b2.html</anchorfile>
      <anchor>ga8d7de5c00a3b6cfc1fc4a8ed3bea53b2</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr std::size_t</type>
      <name>kumi::count</name>
      <anchorfile>group__queries_ga34b674518c68e4cced2155d8da86f793.html</anchorfile>
      <anchor>ga34b674518c68e4cced2155d8da86f793</anchor>
      <arglist>(T const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr std::size_t</type>
      <name>kumi::count_if</name>
      <anchorfile>group__queries_ga6e626baf1ad5f29106db9428aa55f85d.html</anchorfile>
      <anchor>ga6e626baf1ad5f29106db9428aa55f85d</anchor>
      <arglist>(T const &amp;ts, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::locate</name>
      <anchorfile>group__queries_ga5b528cf4282e026dc1efb52ab546bf81.html</anchorfile>
      <anchor>ga5b528cf4282e026dc1efb52ab546bf81</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t, Pred p) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_ga5efc50044b53b7bb4c17ba3a521c289a.html</anchorfile>
      <anchor>ga5efc50044b53b7bb4c17ba3a521c289a</anchor>
      <arglist>(Tuple const &amp;ts) noexcept</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr bool</type>
      <name>kumi::none_of</name>
      <anchorfile>group__queries_gaad40e49ccd63af4301c797b29b371394.html</anchorfile>
      <anchor>gaad40e49ccd63af4301c797b29b371394</anchor>
      <arglist>(Tuple const &amp;ts, Pred p) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>concepts</name>
    <title>Tuple Related Concepts</title>
    <filename>group__concepts.html</filename>
    <concept>kumi::std_tuple_compatible</concept>
    <concept>kumi::product_type</concept>
    <concept>kumi::sized_product_type</concept>
    <concept>kumi::sized_product_type_or_more</concept>
    <concept>kumi::non_empty_product_type</concept>
    <concept>kumi::homogeneous_product_type</concept>
    <concept>kumi::equality_comparable</concept>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">kumi::element</class>
    <class kind="struct">kumi::is_homogeneous</class>
    <class kind="struct">kumi::is_product_type</class>
    <class kind="struct">kumi::member</class>
    <class kind="struct">kumi::size</class>
  </compound>
  <compound kind="group">
    <name>transforms</name>
    <title>Tuple Transformations</title>
    <filename>group__transforms.html</filename>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::apply</name>
      <anchorfile>group__transforms_ga612ed868d8ee0ecabcdaa0d6a7c116fb.html</anchorfile>
      <anchor>ga612ed868d8ee0ecabcdaa0d6a7c116fb</anchor>
      <arglist>(Function &amp;&amp;f, Tuple &amp;&amp;t) noexcept(_::supports_nothrow_apply&lt; Function &amp;&amp;, Tuple &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each</name>
      <anchorfile>group__transforms_ga757e3791ec5e2353fa1f52ec6dafdcb1.html</anchorfile>
      <anchor>ga757e3791ec5e2353fa1f52ec6dafdcb1</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr void</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__transforms_gab74a95670c1baa3ec7e7905d42a5f216.html</anchorfile>
      <anchor>gab74a95670c1baa3ec7e7905d42a5f216</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t, Tuples &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map</name>
      <anchorfile>group__transforms_ga8a4e424cfc506fb8fd2939ebe24382ce.html</anchorfile>
      <anchor>ga8a4e424cfc506fb8fd2939ebe24382ce</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::map_index</name>
      <anchorfile>group__transforms_ga24c0a7632bd20e448dd7ac2d18e1168c.html</anchorfile>
      <anchor>ga24c0a7632bd20e448dd7ac2d18e1168c</anchor>
      <arglist>(Function f, Tuple &amp;&amp;t0, Tuples &amp;&amp;...others)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>tuple</name>
    <title>Tuple Types and Functions</title>
    <filename>group__tuple.html</filename>
    <class kind="class">kumi::tuple</class>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::tuple::operator&lt;&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf6739a069131e315597688e5b3cf5df9</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple const &amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator==</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gaf074114f7e38446c5e298e6701e8a54b</anchor>
      <arglist>(tuple const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr auto</type>
      <name>kumi::tuple::operator&lt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac0b978b3e13c057400e145cc8ac174b0</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>kumi::tuple::operator&lt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac139a2d53851de1cad516a46c5f5b890</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>kumi::tuple::operator&gt;</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gab8a56dde0a34774be10c93e2ead36db8</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>KUMI_TRIVIAL friend constexpr auto</type>
      <name>kumi::tuple::operator&gt;=</name>
      <anchorfile>group__tuple.html</anchorfile>
      <anchor>gac63791b4319477192bf982cb834e2985</anchor>
      <arglist>(tuple const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>kumi::tuple::tuple</name>
      <anchorfile>group__tuple_ga446a0931c46caf9cfb2f3977a2492624.html</anchorfile>
      <anchor>ga446a0931c46caf9cfb2f3977a2492624</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;... &gt;</type>
      <name>kumi::tuple::tie</name>
      <anchorfile>group__tuple_ga3b5a893567431a62dce006d10f23854b.html</anchorfile>
      <anchor>ga3b5a893567431a62dce006d10f23854b</anchor>
      <arglist>(Ts &amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; Ts &amp;&amp;... &gt;</type>
      <name>kumi::tuple::forward_as_tuple</name>
      <anchorfile>group__tuple_ga2e59034f40a923f671b72a88cc1ed045.html</anchorfile>
      <anchor>ga2e59034f40a923f671b72a88cc1ed045</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr tuple&lt; typename std::unwrap_ref_decay&lt; Ts &gt;::type... &gt;</type>
      <name>kumi::tuple::make_tuple</name>
      <anchorfile>group__tuple_ga7a585805b36bec6b2c275b6f2ced67fe.html</anchorfile>
      <anchor>ga7a585805b36bec6b2c275b6f2ced67fe</anchor>
      <arglist>(Ts &amp;&amp;...ts)</arglist>
    </member>
    <member kind="function">
      <type>KUMI_TRIVIAL_NODISCARD constexpr auto</type>
      <name>kumi::tuple::to_ref</name>
      <anchorfile>group__tuple_ga8c39a63412ff38a02ffd6bc2394581ca.html</anchorfile>
      <anchor>ga8c39a63412ff38a02ffd6bc2394581ca</anchor>
      <arglist>(Type &amp;&amp;t)</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::tuple::get</name>
      <anchorfile>group__tuple_ga7b9b1b3fbe3d201542691bee350d8a08.html</anchorfile>
      <anchor>ga7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>changelog</name>
    <title>Change Log</title>
    <filename>changelog.html</filename>
    <docanchor file="changelog.html">md____w_kumi_kumi_doc_changelog</docanchor>
  </compound>
  <compound kind="page">
    <name>licence</name>
    <title>Licence</title>
    <filename>licence.html</filename>
    <docanchor file="licence.html">md____w_kumi_kumi_doc_licence</docanchor>
  </compound>
  <compound kind="page">
    <name>setup</name>
    <title>Setup</title>
    <filename>setup.html</filename>
    <docanchor file="setup.html" title="Install from the source">setup-source</docanchor>
    <docanchor file="setup.html" title="Standalone setup">setup-standalone</docanchor>
    <docanchor file="setup.html" title="CMake FetchContent">setup-fetchcontent</docanchor>
    <docanchor file="setup.html" title="Setup with CPM">setup-cpm</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>The C++20 Compact Tuple Tools</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
