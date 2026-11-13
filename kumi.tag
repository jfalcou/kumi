<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
  <compound kind="struct">
    <name>kumi::apply_traits</name>
    <filename>structkumi_1_1apply__traits.html</filename>
    <templarg>template&lt; typename... &gt; typename Traits</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Seq</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::array</name>
    <filename>structkumi_1_1array.html</filename>
    <templarg>typename T</templarg>
    <templarg>std::size_t N</templarg>
    <member kind="function">
      <type>constexpr array &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aa6879ff5721afd317e81b8235c221feb</anchor>
      <arglist>(array&lt; U, N &gt; &amp;&amp;other) noexcept(std::is_nothrow_assignable_v&lt; T &amp;, U &amp;&amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr array &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a0187989fae388367996e22660c80238b</anchor>
      <arglist>(array&lt; U, N &gt; const &amp;other) noexcept(std::is_nothrow_assignable_v&lt; T &amp;, U const &amp; &gt;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a9dc623cf8ee077203f491d210e8d0205</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a07ccbb74576a7a13ae44148f096d1f06</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aaf2f21de80e184d728322101a7a8e0d4</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a7ba892cc39c773ecdae9d0d01d6d8768</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a10bef61fd0a02e497478798c7333237b</anchor>
      <arglist>(!std::convertible_to&lt; T const &amp;, U &gt;) const expr operator array&lt; U</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>ad5ba7415a64f543253b7b09e85797a92</anchor>
      <arglist>(!std::convertible_to&lt; T &amp;, U &gt;) const expr operator array&lt; U</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr void</type>
      <name>swap</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a152cfa24086d4f3f5c40c80245e8231c</anchor>
      <arglist>(array &amp;a, array &amp;b) noexcept(std::is_nothrow_swappable_v&lt; T &gt;)</arglist>
    </member>
    <member kind="function">
      <type>std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a4d3790f976390b9c704529e436eb90dd</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, array&lt; T, N &gt; const &amp;a) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>adcc8d526e4d5674f453716af6cc1e5f3</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>ae8cab8261c603e758154a0239ec2613c</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a8d1bc1c4364b25df9b0431dc7ddad7b0</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a28abb6ace51e3cd5e4a112f7716d2d21</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a44b90ef96f6acd60c54c4d67becff521</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aebb96b62c4b451b9f7dfc72843937024</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>array</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aa65f3e4fcab288503da561d757da142c</anchor>
      <arglist>(T &amp;&amp;, Ts &amp;&amp;...) -&gt; array&lt; std::unwrap_ref_decay_t&lt; T &gt;, sizeof...(Ts)+1 &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a2a236814b119c1e3e0b1cc5ce062c282</anchor>
      <arglist>(array&lt; T, N &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>abba9991ab8e8494fb1d1a5f045d26e4c</anchor>
      <arglist>(array&lt; T, N &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aff4433e919e93f04a68b424a83f8bffd</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a6252775167e7b3740075a16689c7e278</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a10bef61fd0a02e497478798c7333237b</anchor>
      <arglist>(!std::convertible_to&lt; T const &amp;, U &gt;) const expr operator array&lt; U</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>ad5ba7415a64f543253b7b09e85797a92</anchor>
      <arglist>(!std::convertible_to&lt; T &amp;, U &gt;) const expr operator array&lt; U</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>adcc8d526e4d5674f453716af6cc1e5f3</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>ae8cab8261c603e758154a0239ec2613c</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a8d1bc1c4364b25df9b0431dc7ddad7b0</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a28abb6ace51e3cd5e4a112f7716d2d21</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a44b90ef96f6acd60c54c4d67becff521</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aebb96b62c4b451b9f7dfc72843937024</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>array</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aa65f3e4fcab288503da561d757da142c</anchor>
      <arglist>(T &amp;&amp;, Ts &amp;&amp;...) -&gt; array&lt; std::unwrap_ref_decay_t&lt; T &gt;, sizeof...(Ts)+1 &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a2a236814b119c1e3e0b1cc5ce062c282</anchor>
      <arglist>(array&lt; T, N &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>abba9991ab8e8494fb1d1a5f045d26e4c</anchor>
      <arglist>(array&lt; T, N &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aff4433e919e93f04a68b424a83f8bffd</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a6252775167e7b3740075a16689c7e278</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::as</name>
    <filename>structkumi_1_1as.html</filename>
    <templarg>typename T</templarg>
    <member kind="typedef">
      <type>T</type>
      <name>type</name>
      <anchorfile>structkumi_1_1as.html</anchorfile>
      <anchor>ae0ed33d79b1955359c95eb5e572f7305</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::as_array</name>
    <filename>structkumi_1_1as__array.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::as_tuple</name>
    <filename>structkumi_1_1as__tuple.html</filename>
    <templarg>typename T</templarg>
    <templarg>template&lt; typename... &gt; class Meta</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_and</name>
    <filename>structkumi_1_1function_1_1boolean__and.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__and.html</anchorfile>
      <anchor>ab76cd8c8f2059169433f16b45d02eecd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_or</name>
    <filename>structkumi_1_1function_1_1boolean__or.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__or.html</anchorfile>
      <anchor>a2f7848820b2e45a83aa776a11a4617c7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::boolean_xor</name>
    <filename>structkumi_1_1function_1_1boolean__xor.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr bool</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1boolean__xor.html</anchorfile>
      <anchor>ae232a2d43a04338bb65254cbc736dbea</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::builder</name>
    <filename>structkumi_1_1builder.html</filename>
    <templarg>typename T</templarg>
  </compound>
  <compound kind="struct">
    <name>kumi::common_product_type</name>
    <filename>structkumi_1_1common__product__type.html</filename>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::field</name>
    <filename>structkumi_1_1field.html</filename>
    <templarg>typename Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>label</name>
      <anchorfile>structkumi_1_1field.html</anchorfile>
      <anchor>acd309440c1fca78c1a64750e7a5482df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>capture_field</name>
      <anchorfile>group__kumi__capture__field.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>field_cast</name>
      <anchorfile>group__kumi__field__cast.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::field&lt; Id, T &gt;</name>
    <filename>structkumi_1_1field_3_01Id_00_01T_01_4.html</filename>
    <templarg>typename Id</templarg>
    <templarg>typename T</templarg>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>label</name>
      <anchorfile>structkumi_1_1field_3_01Id_00_01T_01_4.html</anchorfile>
      <anchor>acd309440c1fca78c1a64750e7a5482df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>capture_field</name>
      <anchorfile>group__kumi__capture__field.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>field_cast</name>
      <anchorfile>group__kumi__field__cast.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::foldable</name>
    <filename>structkumi_1_1function_1_1foldable.html</filename>
    <templarg>typename T</templarg>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1function_1_1foldable.html</anchorfile>
      <anchor>a058a4a0c3293567b0aab034517c2306b</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1function_1_1foldable.html</anchorfile>
      <anchor>a41ffcb368da710bf05ba193e84a3992a</anchor>
      <arglist>(C &amp;&amp;c, foldable &amp;&amp;f)</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>structkumi_1_1function_1_1foldable.html</anchorfile>
      <anchor>a6274172de9a7b4e6c94875ca3401dc5b</anchor>
      <arglist>(foldable &amp;&amp;f, C &amp;&amp;c)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>foldable</name>
      <anchorfile>structkumi_1_1function_1_1foldable.html</anchorfile>
      <anchor>afcef35f6193e023d1434f2b7d45bfd1c</anchor>
      <arglist>(T &amp;&amp;t) -&gt; foldable&lt; std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::identifier</name>
    <filename>structkumi_1_1identifier.html</filename>
    <templarg>typename ID</templarg>
    <templarg>typename Checker</templarg>
    <member kind="typedef">
      <type>identifier&lt; ID, Checker &gt;</type>
      <name>type</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>aae1d9bcd971d43f8831ba98f5d7e2678</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a1cbb7d1e8b6adafe05c6b3f43c94db5d</anchor>
      <arglist>() noexcept=default</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>identifier</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a3b9a31cc021cee475c3dd820c966a104</anchor>
      <arglist>(ID const &amp;id, Checker const &amp;check) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>afd233fd13ed5f9c794f0c2bb02db1429</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; kumi::field&lt; type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr kumi_implementation_defined auto</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a975f7d033f7f599bcdc6f2e049084a92</anchor>
      <arglist>(identifier const &amp;)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1identifier.html</anchorfile>
      <anchor>a4042551a86fea06c6d4be2daec274a35</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, identifier const &amp;) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::index_t</name>
    <filename>structkumi_1_1index__t.html</filename>
    <templarg>std::size_t N</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator std::integral_constant&lt; std::size_t, N &gt;</name>
      <anchorfile>structkumi_1_1index__t.html</anchorfile>
      <anchor>ad9eadb46e256efabde1b1b55a90533d7</anchor>
      <arglist>() const noexcept</arglist>
    </member>
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
  <compound kind="class">
    <name>kumi::label_t</name>
    <filename>structkumi_1_1label__t.html</filename>
    <templarg>kumi::str Label</templarg>
    <member kind="function">
      <type>constexpr</type>
      <name>operator type</name>
      <anchorfile>structkumi_1_1label__t.html</anchorfile>
      <anchor>a31674e0dba7b0039ef163b1c1ebce2fe</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr kumi::str</type>
      <name>value</name>
      <anchorfile>structkumi_1_1label__t.html</anchorfile>
      <anchor>a872221f3e54f331778f4971e6e7407ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>kumi::map_traits</name>
    <filename>structkumi_1_1map__traits.html</filename>
    <templarg>template&lt; typename... &gt; typename Traits</templarg>
    <templarg>typename T</templarg>
    <templarg>typename Seq</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::name</name>
    <filename>structkumi_1_1name.html</filename>
    <templarg>kumi::str ID</templarg>
    <member kind="typedef">
      <type>name&lt; ID &gt;</type>
      <name>type</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a9bf8b825d5ec4deb4d1cb8b5c23f773f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a7f497fc96b78d370ec817a1706041743</anchor>
      <arglist>(T &amp;&amp;v) const noexcept -&gt; kumi::field&lt; type, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr kumi_implementation_defined auto</type>
      <name>to_str</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>aaabcb3ff5e55b5cb53ce40fbaf9aa245</anchor>
      <arglist>(name const &amp;)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1name.html</anchorfile>
      <anchor>a7581a84b154ddc4d1741eff4890d720a</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, name const &amp;) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::numeric_add</name>
    <filename>structkumi_1_1function_1_1numeric__add.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1numeric__add.html</anchorfile>
      <anchor>aa873c7638061899a652e97fdf45e1452</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::numeric_prod</name>
    <filename>structkumi_1_1function_1_1numeric__prod.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr auto</type>
      <name>identity</name>
      <anchorfile>structkumi_1_1function_1_1numeric__prod.html</anchorfile>
      <anchor>a442630c534784c7794c0ced4bbaafcda</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::projection_map</name>
    <filename>structkumi_1_1projection__map.html</filename>
    <templarg>auto... V</templarg>
    <member kind="function" static="yes">
      <type>static consteval auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>af8e6f5fc953903d3d5525220a26b791d</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static consteval bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>a58deb29e4d5dd38ee994e8e65f667627</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>get</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>a197ce3f55a71294cb619b65ba8d8cc89</anchor>
      <arglist>(projection_map const &amp;pm) noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static consteval auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>af8e6f5fc953903d3d5525220a26b791d</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static consteval bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1projection__map.html</anchorfile>
      <anchor>a58deb29e4d5dd38ee994e8e65f667627</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::record</name>
    <filename>structkumi_1_1record.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ab63150147c11b6a233094d96b02a1eeb</anchor>
      <arglist>(record&lt; Us... &gt; &amp;&amp;other) noexcept((std::is_nothrow_assignable_v&lt; typename Ts::type &amp;, std::remove_reference_t&lt; kumi::field_of_t&lt; Ts, record&lt; Us... &gt; &gt; &gt; &amp;&amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr record &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a88921ac5a098037c2166c9c7e1769200</anchor>
      <arglist>(record&lt; Us... &gt; const &amp;other) noexcept((std::is_nothrow_assignable_v&lt; typename Ts::type &amp;, std::remove_reference_t&lt; kumi::field_of_t&lt; Ts, record&lt; Us... &gt; &gt; &gt; const &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>afe22fa7b24c2c6257671ce28a566cce7</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0982b5466f4f0943a5bf42f1a0aff576</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac725adbeb4b65f91058d3bfc91d66335</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae7963719866868799e0ee02626b83d67</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a8d69c24669ea60edfb2253967a09009a</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5cd42a9117ea19ce0a3ed103b1f69b5a</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3a5d33e3f8ec9566ed099bd27ff01c96</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a247bf105ce5d9529452216eb27342779</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a24420aaaf1ba42d322270296d094fbfa</anchor>
      <arglist>(kumi::label_t&lt; Name &gt; l) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a98043c2c63bf512d114f81d4b0364acb</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a486114f35058ce5b0f34835c474a3c36</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac1d95daeb0db9e0733e2e79e65a8c991</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a31c8f07c20352d38c51afd1ca872eec2</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>acbfe3f9bd69057c3c7b228b45e8f82c4</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aab158fc3470145a9215e6bb80474f0a4</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5c9d75f431a2453078baf16553dc9a28</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr void</type>
      <name>swap</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a92c78947b29dbd8a035032fef1e3b7d8</anchor>
      <arglist>(record &amp;a, record &amp;b) noexcept((std::is_nothrow_swappable_v&lt; kumi_implementation_defined &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a58d5d2276354e3780e7963965ddf5698</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, record&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0b13841d53a273eae4e61e8637f9d094</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ab0c7a7dc02f179f880931b51d7cc53eb</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>record</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae9ac76c2474af708950b35e4b58027d6</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>afe22fa7b24c2c6257671ce28a566cce7</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0982b5466f4f0943a5bf42f1a0aff576</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac725adbeb4b65f91058d3bfc91d66335</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae7963719866868799e0ee02626b83d67</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a8d69c24669ea60edfb2253967a09009a</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5cd42a9117ea19ce0a3ed103b1f69b5a</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3a5d33e3f8ec9566ed099bd27ff01c96</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a247bf105ce5d9529452216eb27342779</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a24420aaaf1ba42d322270296d094fbfa</anchor>
      <arglist>(kumi::label_t&lt; Name &gt; l) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a98043c2c63bf512d114f81d4b0364acb</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a486114f35058ce5b0f34835c474a3c36</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac1d95daeb0db9e0733e2e79e65a8c991</anchor>
      <arglist>(kumi::label_t&lt; Name &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a31c8f07c20352d38c51afd1ca872eec2</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>acbfe3f9bd69057c3c7b228b45e8f82c4</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aab158fc3470145a9215e6bb80474f0a4</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a5c9d75f431a2453078baf16553dc9a28</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a9b9b96d4aae04575e8c2ff5ab515b594</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>values</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>aed4f570ae92586a34d7f03b4bc584ebc</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae58c2eac14a343992ac19d9ba01ec6ae</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a7e54e12c537c8dcbafabc215957f0abc</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>identifiers</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ac730d46c3db986909e0c910b74648b4a</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>labels</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a57fe20038a1592ea37e9a8954c013d80</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0b13841d53a273eae4e61e8637f9d094</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ab0c7a7dc02f179f880931b51d7cc53eb</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>record</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae9ac76c2474af708950b35e4b58027d6</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::function::scannable</name>
    <filename>structkumi_1_1function_1_1scannable.html</filename>
    <templarg>typename F</templarg>
    <templarg>typename V</templarg>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator()</name>
      <anchorfile>structkumi_1_1function_1_1scannable.html</anchorfile>
      <anchor>ae2b8d4cb8c7a10c67bc1efd15b375f8d</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1function_1_1scannable.html</anchorfile>
      <anchor>a8c1e8999b59c5cda817381bf6ae3a198</anchor>
      <arglist>(C &amp;&amp;c, scannable &amp;&amp;s)</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr decltype(auto)</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>structkumi_1_1function_1_1scannable.html</anchorfile>
      <anchor>adefe959b56f2d22a08ef8715dfc15cb7</anchor>
      <arglist>(scannable &amp;&amp;s, C &amp;&amp;c)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>scannable</name>
      <anchorfile>structkumi_1_1function_1_1scannable.html</anchorfile>
      <anchor>ac3570f9286b470ae88de5a142941751a</anchor>
      <arglist>(F &amp;&amp;f, T &amp;&amp;t) -&gt; scannable&lt; F, std::unwrap_ref_decay_t&lt; T &gt; &gt;</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::str</name>
    <filename>structkumi_1_1str.html</filename>
    <templarg>std::size_t N</templarg>
  </compound>
  <compound kind="class">
    <name>kumi::tuple</name>
    <filename>structkumi_1_1tuple.html</filename>
    <templarg>typename... Ts</templarg>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2bf09e2253e83b39569ca10256132eca</anchor>
      <arglist>(tuple&lt; Us... &gt; &amp;&amp;other) noexcept((std::is_nothrow_assignable_v&lt; Ts &amp;, Us &amp;&amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr tuple &amp;</type>
      <name>operator=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af5234363a13443cb89d202ff5c396e4a</anchor>
      <arglist>(tuple&lt; Us... &gt; const &amp;other) noexcept((std::is_nothrow_assignable_v&lt; Ts &amp;, Us const &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9642386ee7679de26bcc7be48128073d</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9c771ad0b2f04d7bba28a4e3906d915d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac387bc56430a45ba5e8d797c61b8ff2d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a292267a2b139d90a3238aad166bfcdfa</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad7617c6685a224f58e2c6f45df0cb726</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8c0031b90900565815c006c223c7159c</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a763f1b3e9b47ae1d6fd213ee7828936a</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab187f8ddffa548d7bc17f39bbbcf4b50</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0bbd24629b0ebd7b833364a72e604a67</anchor>
      <arglist>(kumi::label_t&lt; L &gt; s) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac9f408ae6b7545cce710931bd4fc970b</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac1b37d5e96ae8c5fa355b9862c79ed0c</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a361a7552ac0290826eedf4efe15e2859</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a18682a7418347e139227e26868486eca</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a891b26a59ea0b5d496f0f96a128f9bd8</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a338981edc5d3aa6e9e5b0ef604bdb298</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2535ed124742921f2d9f813adebca1b2</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab932ad9cad261df1f0d2edfe464c23fe</anchor>
      <arglist>(!(std::is_convertible_v&lt; Ts const &amp;, Us &gt; &amp;&amp;...)) const expr operator tuple&lt; Us... &gt;() const noexcept((std::is_nothrow_constructible_v&lt; Us, Ts const &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9aeeec894f606cd3efb3c66f8414c931</anchor>
      <arglist>(!(std::is_convertible_v&lt; Ts &amp;, Us &gt; &amp;&amp;...)) const expr operator tuple&lt; Us... &gt;() noexcept((std::is_nothrow_constructible_v&lt; Us, Ts &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0d0957e5314d780693c3d67344a42b3e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af1a74e00134be29916bb7fb6e8cda5f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>identifiers</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a20bf7b884e66f42a41076a4b1535054b</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>labels</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>afcfee8fbd3a138d70cff1edb3485e61e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend constexpr void</type>
      <name>swap</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa3508885774101340eb2db1d2b61ed28</anchor>
      <arglist>(tuple &amp;a, tuple &amp;b) noexcept((std::is_nothrow_swappable_v&lt; Ts &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ae4a6f765f9c255d795ba8ab2fe213639</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad8fed866ec4f0a7bec029a5caccb4d06</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa163bc956286a74832bc716e7bdf6c8e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad24a079fe765887d229a4a6e2773ae93</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6bf7895513944455a880219d7aac3fca</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7ad00985e7c37ea5a984d3aa9e51a57e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acfbd7477060ef62349adf34c16496e4f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>tuple</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a612d97f050a7b0eb9999f40c045779bf</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a808bbc50bf9ed9681c41b55f5444e9ea</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>adcfd380d3fc78581e99125f49e32ae0a</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aaea300b4c7c7cbe1103612b28ba470b5</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9642386ee7679de26bcc7be48128073d</anchor>
      <arglist>(kumi::index_t&lt; I &gt; i) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9c771ad0b2f04d7bba28a4e3906d915d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac387bc56430a45ba5e8d797c61b8ff2d</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a292267a2b139d90a3238aad166bfcdfa</anchor>
      <arglist>(kumi::index_t&lt; I &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad7617c6685a224f58e2c6f45df0cb726</anchor>
      <arglist>(kumi::as&lt; T &gt; type) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a8c0031b90900565815c006c223c7159c</anchor>
      <arglist>(kumi::as&lt; T &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a763f1b3e9b47ae1d6fd213ee7828936a</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab187f8ddffa548d7bc17f39bbbcf4b50</anchor>
      <arglist>(kumi::as&lt; T &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0bbd24629b0ebd7b833364a72e604a67</anchor>
      <arglist>(kumi::label_t&lt; L &gt; s) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac9f408ae6b7545cce710931bd4fc970b</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ac1b37d5e96ae8c5fa355b9862c79ed0c</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a361a7552ac0290826eedf4efe15e2859</anchor>
      <arglist>(kumi::label_t&lt; L &gt;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a18682a7418347e139227e26868486eca</anchor>
      <arglist>(Id const &amp;) &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a891b26a59ea0b5d496f0f96a128f9bd8</anchor>
      <arglist>(Id const &amp;) &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a338981edc5d3aa6e9e5b0ef604bdb298</anchor>
      <arglist>(Id const &amp;) const &amp;&amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>operator[]</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a2535ed124742921f2d9f813adebca1b2</anchor>
      <arglist>(Id const &amp;) const &amp;noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ab932ad9cad261df1f0d2edfe464c23fe</anchor>
      <arglist>(!(std::is_convertible_v&lt; Ts const &amp;, Us &gt; &amp;&amp;...)) const expr operator tuple&lt; Us... &gt;() const noexcept((std::is_nothrow_constructible_v&lt; Us, Ts const &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>explicit</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a9aeeec894f606cd3efb3c66f8414c931</anchor>
      <arglist>(!(std::is_convertible_v&lt; Ts &amp;, Us &gt; &amp;&amp;...)) const expr operator tuple&lt; Us... &gt;() noexcept((std::is_nothrow_constructible_v&lt; Us, Ts &amp; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>size</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a0d0957e5314d780693c3d67344a42b3e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr bool</type>
      <name>empty</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>af1a74e00134be29916bb7fb6e8cda5f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>identifiers</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a20bf7b884e66f42a41076a4b1535054b</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static constexpr auto</type>
      <name>labels</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>afcfee8fbd3a138d70cff1edb3485e61e</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad8fed866ec4f0a7bec029a5caccb4d06</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa163bc956286a74832bc716e7bdf6c8e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad24a079fe765887d229a4a6e2773ae93</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6bf7895513944455a880219d7aac3fca</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7ad00985e7c37ea5a984d3aa9e51a57e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acfbd7477060ef62349adf34c16496e4f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>tuple</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a612d97f050a7b0eb9999f40c045779bf</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a808bbc50bf9ed9681c41b55f5444e9ea</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>adcfd380d3fc78581e99125f49e32ae0a</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aaea300b4c7c7cbe1103612b28ba470b5</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>kumi::unit</name>
    <filename>structkumi_1_1unit.html</filename>
  </compound>
  <compound kind="class">
    <name>kumi::unknown</name>
    <filename>structkumi_1_1unknown.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::compatible_product_types</name>
    <filename>conceptkumi_1_1concepts_1_1compatible__product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::container</name>
    <filename>conceptkumi_1_1concepts_1_1container.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_identifier</name>
    <filename>conceptkumi_1_1concepts_1_1contains__identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_label</name>
    <filename>conceptkumi_1_1concepts_1_1contains__label.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::contains_type</name>
    <filename>conceptkumi_1_1concepts_1_1contains__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equality_comparable</name>
    <filename>conceptkumi_1_1concepts_1_1equality__comparable.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::equivalent</name>
    <filename>conceptkumi_1_1concepts_1_1equivalent.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::field</name>
    <filename>conceptkumi_1_1concepts_1_1field.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::follows_same_semantic</name>
    <filename>conceptkumi_1_1concepts_1_1follows__same__semantic.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::fully_named</name>
    <filename>conceptkumi_1_1concepts_1_1fully__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::has_named_fields</name>
    <filename>conceptkumi_1_1concepts_1_1has__named__fields.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::homogeneous_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1homogeneous__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::identifier</name>
    <filename>conceptkumi_1_1concepts_1_1identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::index</name>
    <filename>conceptkumi_1_1concepts_1_1index.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::monoid</name>
    <filename>conceptkumi_1_1concepts_1_1monoid.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::non_empty_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1non__empty__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::power_type</name>
    <filename>conceptkumi_1_1concepts_1_1power__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::power_types</name>
    <filename>conceptkumi_1_1concepts_1_1power__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::product_type</name>
    <filename>conceptkumi_1_1concepts_1_1product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::product_types</name>
    <filename>conceptkumi_1_1concepts_1_1product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::projection</name>
    <filename>conceptkumi_1_1concepts_1_1projection.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::projection_map</name>
    <filename>conceptkumi_1_1concepts_1_1projection__map.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::queryable_by_identifier</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__identifier.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::queryable_by_label</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__label.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::queryable_by_type</name>
    <filename>conceptkumi_1_1concepts_1_1queryable__by__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::record_type</name>
    <filename>conceptkumi_1_1concepts_1_1record__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::record_types</name>
    <filename>conceptkumi_1_1concepts_1_1record__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::sized_product_type_or_more</name>
    <filename>conceptkumi_1_1concepts_1_1sized__product__type__or__more.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::static_container</name>
    <filename>conceptkumi_1_1concepts_1_1static__container.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniform_product_types</name>
    <filename>conceptkumi_1_1concepts_1_1uniform__product__types.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_labeled</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__labeled.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_named</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__named.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::uniquely_typed</name>
    <filename>conceptkumi_1_1concepts_1_1uniquely__typed.html</filename>
  </compound>
  <compound kind="concept">
    <name>kumi::concepts::unit_type</name>
    <filename>conceptkumi_1_1concepts_1_1unit__type.html</filename>
  </compound>
  <compound kind="namespace">
    <name>kumi</name>
    <filename>namespacekumi.html</filename>
    <class kind="struct">kumi::apply_traits</class>
    <class kind="class">kumi::array</class>
    <class kind="class">kumi::as</class>
    <class kind="struct">kumi::as_array</class>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::builder</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="class">kumi::field</class>
    <class kind="struct">kumi::field&lt; Id, T &gt;</class>
    <class kind="class">kumi::identifier</class>
    <class kind="class">kumi::index_t</class>
    <class kind="class">kumi::label_t</class>
    <class kind="struct">kumi::map_traits</class>
    <class kind="class">kumi::name</class>
    <class kind="class">kumi::projection_map</class>
    <class kind="class">kumi::record</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::tuple</class>
    <class kind="class">kumi::unit</class>
    <class kind="class">kumi::unknown</class>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>container_type_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gacf63a95bf29987c5639c10ce15e6937b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::tuple_element_t&lt; I, std::remove_cvref_t&lt; T &gt; &gt;</type>
      <name>element_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga8ba508c6d1dfb63ff6fec24deb84d66e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(get&lt; kumi_implementation_defined{}&gt;(std::declval&lt; T &amp;&amp; &gt;()))</type>
      <name>field_of_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gad4afc653b2f97e5be9ed92756cfc32ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(get&lt; I &gt;(std::declval&lt; T &amp;&amp; &gt;()))</type>
      <name>member_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaca6d42cbec766fb8d43a4060077e2624</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>stored_element_t</name>
      <anchorfile>group__kumi__record__traits.html</anchorfile>
      <anchor>gaa957535657d5741421f09c44c5faaa62</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>stored_member_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga17e8e213d54b65fdd4de0ec25916d3e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bind_back</name>
      <anchorfile>group__kumi__bind__back.html</anchorfile>
      <anchor>ga02fbf71873458cc8a364a7f6efcfadf2</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>bind_front</name>
      <anchorfile>group__kumi__bind__front.html</anchorfile>
      <anchor>ga08c383ce2fb100dda15baf96b4e60d2f</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>field_value_of</name>
      <anchorfile>group__kumi__field__value__of.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_field</name>
      <anchorfile>group__kumi__get__index__of__field.html</anchorfile>
      <anchor>ga2fc46ed70d43d14ca52860896fd1e364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_label</name>
      <anchorfile>group__kumi__get__index__of__label.html</anchorfile>
      <anchor>ga6c5b5c12c2baa75189a7d94e55fbfe17</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>get_index_of_type</name>
      <anchorfile>group__kumi__get__index__of__type.html</anchorfile>
      <anchor>ga15172fcc47fe0c88931be39b9c3633fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>identifier_of</name>
      <anchorfile>group__kumi__identifier__of.html</anchorfile>
      <anchor>gab3919ec6f8098dd1fdafe9c3a79ef0dc</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>identifiers</name>
      <anchorfile>group__kumi__identifiers.html</anchorfile>
      <anchor>ga63a205c6c2502e733987043857abea05</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>indexes</name>
      <anchorfile>group__kumi__indexes.html</anchorfile>
      <anchor>ga6882a4ada4935fa0fd4ef32ce3716ffb</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>invoke</name>
      <anchorfile>group__kumi__invoke.html</anchorfile>
      <anchor>gace270cfbaa7b0d519fdf03f8225f2908</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts)</arglist>
    </member>
    <member kind="function">
      <type>constexpr R</type>
      <name>invoke_r</name>
      <anchorfile>group__kumi__invoke__r.html</anchorfile>
      <anchor>ga2ad666793ad04ea9b66c84b83f41f375</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r_v&lt; R, C, Ts... &gt;)</arglist>
    </member>
    <member kind="function">
      <type>consteval kumi_implementation_defined auto</type>
      <name>label_of</name>
      <anchorfile>group__kumi__label__of.html</anchorfile>
      <anchor>ga83a3a02d003803934382a94c4f126264</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>consteval auto</type>
      <name>make_indexes</name>
      <anchorfile>group__kumi__make__indexes.html</anchorfile>
      <anchor>gadba148c334bcf52088dc64992c270fdd</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_c</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_id</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&quot;&quot;_l</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga1eb529eb7ccadf0b5e632c132c2b9750</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr bool</type>
      <name>operator==</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a79ad96867cb40b26d3f8929df3177aad</anchor>
      <arglist>(L const &amp;, R const &amp;)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>predicate</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>projection_map</name>
      <anchorfile>group__kumi__projection__map.html</anchorfile>
      <anchor>ga0ac9f243b64bbbabc2bad542ca03c035</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts</arglist>
    </member>
    <member kind="variable">
      <type>constexpr all_of_t</type>
      <name>all_of</name>
      <anchorfile>group__kumi__all__of.html</anchorfile>
      <anchor>gaffdb8063b72f079107cd8a7e293ba298</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr all_unique_t</type>
      <name>all_unique</name>
      <anchorfile>group__kumi__all__unique.html</anchorfile>
      <anchor>ga71bbbe8da94919e242bd3ded80ab6776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>all_unique_names_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga29ec70c788b9f655ef3b0f013ad63cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>all_uniques_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga070181668492faff7e8b283ced082df3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr any_of_t</type>
      <name>any_of</name>
      <anchorfile>group__kumi__any__of.html</anchorfile>
      <anchor>ga79566892f932a2308e23b5f21b95086f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr apply_t</type>
      <name>apply</name>
      <anchorfile>group__kumi__apply.html</anchorfile>
      <anchor>ga4c69a49971100b7bc9c7effd7c43f191</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr apply_field_t</type>
      <name>apply_field</name>
      <anchorfile>group__kumi__apply__field.html</anchorfile>
      <anchor>ga992364930a4a5a5b64b26730773536ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>are_uniform_product_types_v</name>
      <anchorfile>group__kumi__are__uniform__product__types__v.html</anchorfile>
      <anchor>ga8a470806958b269680709330b608b042</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr as_flat_ptr_t</type>
      <name>as_flat_ptr</name>
      <anchorfile>group__kumi__as__flat__ptr.html</anchorfile>
      <anchor>ga6368952a2f6a506de75aa0e01569eab6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr back_t</type>
      <name>back</name>
      <anchorfile>group__kumi__back.html</anchorfile>
      <anchor>gae635e0c094282372ff5393840b6f52c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_and_t</type>
      <name>bit_and</name>
      <anchorfile>group__kumi__bit__and.html</anchorfile>
      <anchor>ga17c3d8bab8099c4756a8b6fb4e9d4380</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_or_t</type>
      <name>bit_or</name>
      <anchorfile>group__kumi__bit__or.html</anchorfile>
      <anchor>ga74fa99e87e80d8bb15ea6694e381bd49</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bit_xor_t</type>
      <name>bit_xor</name>
      <anchorfile>group__kumi__bit__xor.html</anchorfile>
      <anchor>ga2797c81f32afec2f2ce4856a5155807c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cartesian_product_t</type>
      <name>cartesian_product</name>
      <anchorfile>group__kumi__cartesian__product.html</anchorfile>
      <anchor>ga39128fad2c11b9fea55558222a87721c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr cat_t</type>
      <name>cat</name>
      <anchorfile>group__kumi__cat.html</anchorfile>
      <anchor>ga4550222df58187f71b1b1347500e324a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, N &gt;</type>
      <name>chunks</name>
      <anchorfile>group__kumi__chunks.html</anchorfile>
      <anchor>gaf4b0bcda72790c2ac55519adaf89456e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr compress_t</type>
      <name>compress</name>
      <anchorfile>group__kumi__compress.html</anchorfile>
      <anchor>gaa9d6196838118af0a837160d8bbf532c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr std::size_t</type>
      <name>container_size_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gad9f0e77ce97f1a124d20a378a8bf3c57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_t</type>
      <name>contains</name>
      <anchorfile>group__kumi__contains.html</anchorfile>
      <anchor>ga3a9b6e2d0fbdace9e57b3846d24a3b57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_any_t</type>
      <name>contains_any</name>
      <anchorfile>group__kumi__contains__any.html</anchorfile>
      <anchor>ga639f59cb294f670d2f2c468c4ef204d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_none_t</type>
      <name>contains_none</name>
      <anchorfile>group__kumi__contains__none.html</anchorfile>
      <anchor>ga7b1bbe80c513abfdedd1196f027601d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr contains_only_t</type>
      <name>contains_only</name>
      <anchorfile>group__kumi__contains__only.html</anchorfile>
      <anchor>ga36431211bf121466392b290459a45498</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_t</type>
      <name>count</name>
      <anchorfile>group__kumi__count.html</anchorfile>
      <anchor>ga8240f113b5feb1dcc826949f28f17a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr count_if_t</type>
      <name>count_if</name>
      <anchorfile>group__kumi__count__if.html</anchorfile>
      <anchor>gaec0fb27dc2250b97648bc52b8e83b561</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_left_t</type>
      <name>exclusive_scan_left</name>
      <anchorfile>group__kumi__exclusive__scan__left.html</anchorfile>
      <anchor>ga529950ddf6573473b2f9b7ec886c61f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr exclusive_scan_right_t</type>
      <name>exclusive_scan_right</name>
      <anchorfile>group__kumi__exclusive__scan__right.html</anchorfile>
      <anchor>gaa66bb36d76db2d7854196bc156fb35c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr extract_t</type>
      <name>extract</name>
      <anchorfile>group__kumi__extract.html</anchorfile>
      <anchor>ga1a7617bafd6f8598cca8e7e6a5c6f383</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fill_t&lt; N &gt;</type>
      <name>fill</name>
      <anchorfile>group__kumi__fill.html</anchorfile>
      <anchor>gafd5d1c6d3d2fcb3c424826b8bddb8b0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_t&lt; Pred &gt;</type>
      <name>filter</name>
      <anchorfile>group__kumi__filter.html</anchorfile>
      <anchor>ga2c9b5ff6b698c7dcb0feb2da1679fa9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr filter_not_t&lt; Pred &gt;</type>
      <name>filter_not</name>
      <anchorfile>group__kumi__filter__not.html</anchorfile>
      <anchor>ga750bc3d3425c955e1be6ef1b3879c314</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_t</type>
      <name>flatten</name>
      <anchorfile>group__kumi__flatten.html</anchorfile>
      <anchor>ga49acccc42ec8af7b96b63e8f38796df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr flatten_all_t</type>
      <name>flatten_all</name>
      <anchorfile>group__kumi__flatten__all.html</anchorfile>
      <anchor>gaa780fd338fb61c86f226ae05adfaf426</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_left_t</type>
      <name>fold_left</name>
      <anchorfile>group__kumi__fold__left.html</anchorfile>
      <anchor>gac7fc6bc4e0aff96cca71f0a64b0f2aa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr fold_right_t</type>
      <name>fold_right</name>
      <anchorfile>group__kumi__fold__right.html</anchorfile>
      <anchor>gaee418c18e09e3b1789c23ec00681db42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr for_each_t</type>
      <name>for_each</name>
      <anchorfile>group__kumi__for__each.html</anchorfile>
      <anchor>ga58c4bb5e62083b4b37396d39c6446164</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr for_each_field_t</type>
      <name>for_each_field</name>
      <anchorfile>group__kumi__for__each__field.html</anchorfile>
      <anchor>gafb2ad3366fa0af8cb1f3c32cb6c6970d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr for_each_index_t</type>
      <name>for_each_index</name>
      <anchorfile>group__kumi__for__each__index.html</anchorfile>
      <anchor>ga34623706699cbbd62d626e3cc49aa8dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr forward_as_array_t</type>
      <name>forward_as_array</name>
      <anchorfile>group__kumi__forward__as__array.html</anchorfile>
      <anchor>gaa93098695e1bc5a6db9572a70b5a2cd8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr forward_as_record_t&lt; Fields... &gt;</type>
      <name>forward_as_record</name>
      <anchorfile>group__kumi__forward__as__record.html</anchorfile>
      <anchor>gacfd38acd9ecb27bff2bb2ad0f885e326</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr forward_as_tuple_t</type>
      <name>forward_as_tuple</name>
      <anchorfile>group__kumi__forward__as__tuple.html</anchorfile>
      <anchor>ga934bd052835c7cc48a870fbc7c86e6ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr from_array_t&lt; Type &gt;</type>
      <name>from_array</name>
      <anchorfile>group__kumi__from__array.html</anchorfile>
      <anchor>gaca20d574b6dd574d6628fae65ea688fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr from_record_t&lt; Type &gt;</type>
      <name>from_record</name>
      <anchorfile>group__kumi__from__record.html</anchorfile>
      <anchor>gae4456196aadb75484ad0b061c83b3f95</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr from_tuple_t&lt; Type &gt;</type>
      <name>from_tuple</name>
      <anchorfile>group__kumi__from__tuple.html</anchorfile>
      <anchor>gaebb54917d0e966b2f64aaa91dedcd5dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr front_t</type>
      <name>front</name>
      <anchorfile>group__kumi__front.html</anchorfile>
      <anchor>gaa1618c96c4c7003afeccfb19e25b35bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr generate_t&lt; N &gt;</type>
      <name>generate</name>
      <anchorfile>group__kumi__generate.html</anchorfile>
      <anchor>gaba2efbda8df6baaccd4e35343d70163f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>has_static_size_v</name>
      <anchorfile>group__kumi__has__static__size__v.html</anchorfile>
      <anchor>gaaaac9da4c0098fbf974cd6917827dae4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>if_</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_left_t</type>
      <name>inclusive_scan_left</name>
      <anchorfile>group__kumi__inclusive__scan__left.html</anchorfile>
      <anchor>ga1389eee6fb884b34ed4957884ecd39a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inclusive_scan_right_t</type>
      <name>inclusive_scan_right</name>
      <anchorfile>group__kumi__inclusive__scan__right.html</anchorfile>
      <anchor>gab55848ee4bd1b0cc0f22015a2bac5047</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr inner_product_t</type>
      <name>inner_product</name>
      <anchorfile>group__kumi__inner__product.html</anchorfile>
      <anchor>ga712c681a51bdbc86d41b160deddd2e1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr iota_t&lt; N &gt;</type>
      <name>iota</name>
      <anchorfile>group__kumi__iota.html</anchorfile>
      <anchor>gace6e022bb94a706731299b9d395ac10d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_comparable_v</name>
      <anchorfile>group__kumi__is__comparable__v.html</anchorfile>
      <anchor>ga02be876fed0356a37924a4df900feace</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_container_v</name>
      <anchorfile>group__kumi__is__container__v.html</anchorfile>
      <anchor>ga02b588394b12893e71b1d6162db0b4b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_equality_comparable_v</name>
      <anchorfile>group__kumi__is__equality__comparable__v.html</anchorfile>
      <anchor>ga156cb23641777bc9b29e3d3cff87aba4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_equivalent_v</name>
      <anchorfile>group__kumi__is__equivalent__v.html</anchorfile>
      <anchor>ga65a2b6e28cd4ab58cfaffd90fea1b215</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_homogeneous_v</name>
      <anchorfile>group__kumi__is__homogeneous__v.html</anchorfile>
      <anchor>ga444ecc58235c6cb4f805f5bb03409e4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_instance_of_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaf70c64a5b0d21e1bcc3e51077c06d18d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_ordered_v</name>
      <anchorfile>group__kumi__is__ordered__v.html</anchorfile>
      <anchor>ga88b0cafd09ba2a1bbc6e301f70d9ba17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_power_type_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaa1989d911d3452c800cd62f0c9d78607</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_product_type_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga543f9adb09ce98ab19a15e3a90c52656</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_projection_map_v</name>
      <anchorfile>group__kumi__is__projection__map__v.html</anchorfile>
      <anchor>gac535fd8eadc87407e3132a7fceda4ab1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>is_record_type_v</name>
      <anchorfile>group__kumi__is__record__type__v.html</anchorfile>
      <anchor>ga75612200d87c3aa30f068205aa882e2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr locate_t</type>
      <name>locate</name>
      <anchorfile>group__kumi__locate.html</anchorfile>
      <anchor>ga39f807d6c2b8909a712d431acde4153e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr make_array_t</type>
      <name>make_array</name>
      <anchorfile>group__kumi__make__array.html</anchorfile>
      <anchor>ga1f35cbd4396ea2b88d6c34f63c02c8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr make_record_t</type>
      <name>make_record</name>
      <anchorfile>group__kumi__make__record.html</anchorfile>
      <anchor>ga931b45076a3ac621c248efa48881b59a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr make_tuple_t</type>
      <name>make_tuple</name>
      <anchorfile>group__kumi__make__tuple.html</anchorfile>
      <anchor>ga2a3a7b464afb602d8a722178ac517da8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_t</type>
      <name>map</name>
      <anchorfile>group__kumi__map.html</anchorfile>
      <anchor>gaeaba737291ba1085d77272eae38a016e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_field_t</type>
      <name>map_field</name>
      <anchorfile>group__kumi__map__field.html</anchorfile>
      <anchor>gafe68ca583e3e822b20f60ff35e5aa9d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_index_t</type>
      <name>map_index</name>
      <anchorfile>group__kumi__map__index.html</anchorfile>
      <anchor>ga64a8c36072828fb7b724ba0ab8fc59bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr map_reduce_t</type>
      <name>map_reduce</name>
      <anchorfile>group__kumi__map__reduce.html</anchorfile>
      <anchor>ga396afbfbcefa48f06ad76a34b6f0b523</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr max_t</type>
      <name>max</name>
      <anchorfile>group__kumi__max.html</anchorfile>
      <anchor>gab76e53ad197280669806cae2c0cc130c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr max_flat_t</type>
      <name>max_flat</name>
      <anchorfile>group__kumi__max__flat.html</anchorfile>
      <anchor>ga718f20d4004a2d3a409bfcfda289ba34</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr member_cast_t&lt; T &gt;</type>
      <name>member_cast</name>
      <anchorfile>group__kumi__member__cast.html</anchorfile>
      <anchor>gad2e4009d5d28df5090885b030f08f1f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr members_of_t</type>
      <name>members_of</name>
      <anchorfile>group__kumi__members__of.html</anchorfile>
      <anchor>ga50426580ce9abca59b6a14b398b312ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr min_t</type>
      <name>min</name>
      <anchorfile>group__kumi__min.html</anchorfile>
      <anchor>gaafd0c178628f6f756bf0d73a34e75b2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr min_flat_t</type>
      <name>min_flat</name>
      <anchorfile>group__kumi__min__flat.html</anchorfile>
      <anchor>ga31c5b32bd084cb6f18d19706d0f809bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr none_of_t</type>
      <name>none_of</name>
      <anchorfile>group__kumi__none__of.html</anchorfile>
      <anchor>ga26e030c97733248f67dd2c8fbf527602</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>npos</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>a864eeb606afbe8cb4df27a765e0411c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr kumi::only_t&lt; T &gt;</type>
      <name>only</name>
      <anchorfile>group__kumi__only.html</anchorfile>
      <anchor>ga26690952147eaa66ecf74378070ee53b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr partition_t&lt; Pred &gt;</type>
      <name>partition</name>
      <anchorfile>group__kumi__partition.html</anchorfile>
      <anchor>ga4643116b2dc0dfbd0d15fee408a9c18c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr pop_back_t</type>
      <name>pop_back</name>
      <anchorfile>group__kumi__pop__back.html</anchorfile>
      <anchor>ga397f7c5161b7a3ace25c406e83af98fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr pop_front_t</type>
      <name>pop_front</name>
      <anchorfile>group__kumi__pop__front.html</anchorfile>
      <anchor>ga38d1ddeb5090405e79e9b7d898a85133</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr prod_t</type>
      <name>prod</name>
      <anchorfile>group__kumi__prod.html</anchorfile>
      <anchor>ga6c139ebafaebc0f7dbca2fd57aee943c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr push_back_t</type>
      <name>push_back</name>
      <anchorfile>group__kumi__push__back.html</anchorfile>
      <anchor>ga2d60bb8eaba1c8c697b0d4f1e9bf7ce6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr push_front_t</type>
      <name>push_front</name>
      <anchorfile>group__kumi__push__front.html</anchorfile>
      <anchor>gad4bd53f162f63af0cbfbd68d8adb5d5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reduce_t</type>
      <name>reduce</name>
      <anchorfile>group__kumi__reduce.html</anchorfile>
      <anchor>gaf7efbfa530d2396e2ed230cc03e4046e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reindex_t&lt; Projections &gt;</type>
      <name>reindex</name>
      <anchorfile>group__kumi__reindex.html</anchorfile>
      <anchor>ga3594f15dbfba2f6fda0afc8d1542c449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr remove_t</type>
      <name>remove</name>
      <anchorfile>group__kumi__remove.html</anchorfile>
      <anchor>ga0f52ba0b24ce54052784df91c54ac233</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_t&lt; I... &gt;</type>
      <name>reorder</name>
      <anchorfile>group__kumi__reorder.html</anchorfile>
      <anchor>ga32af967d7f453426ccd564d3a0b6c689</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reorder_fields_t&lt; Name... &gt;</type>
      <name>reorder_fields</name>
      <anchorfile>group__kumi__reorder__fields.html</anchorfile>
      <anchor>ga8c42552c8f93dad0b83a3903468d02c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr reverse_t</type>
      <name>reverse</name>
      <anchorfile>group__kumi__reverse.html</anchorfile>
      <anchor>ga48f6e5775e61dca804eda8b0bd354d6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_left_t&lt; R &gt;</type>
      <name>rotate_left</name>
      <anchorfile>group__kumi__rotate__left.html</anchorfile>
      <anchor>gadbc56977f82e2eaefe486c0a9457f01c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr rotate_right_t&lt; R &gt;</type>
      <name>rotate_right</name>
      <anchorfile>group__kumi__rotate__right.html</anchorfile>
      <anchor>gaffd5dbb36e1c70d2fc058ffe03afef3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr std::size_t</type>
      <name>size_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga4dd894f30adf7e5f7ae95124f66d8adb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr split_t</type>
      <name>split</name>
      <anchorfile>group__kumi__split.html</anchorfile>
      <anchor>gadb81f4533e81830674c3fc9577d3de93</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr sum_t</type>
      <name>sum</name>
      <anchorfile>group__kumi__sum.html</anchorfile>
      <anchor>ga3e8b585399de360c3ab55efc2fa0ed8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tie_t</type>
      <name>tie</name>
      <anchorfile>group__kumi__tie.html</anchorfile>
      <anchor>ga79c564af50f6eb1c4aa6dac7f08337cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tie_as_record_t&lt; Fields... &gt;</type>
      <name>tie_as_record</name>
      <anchorfile>group__kumi__record__related.html</anchorfile>
      <anchor>ga45b4db8f009ab12f62d938338d29d536</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, O &gt;</type>
      <name>tiles</name>
      <anchorfile>group__kumi__tiles.html</anchorfile>
      <anchor>ga3d1b4a8309328d854d7b6234fde3aeb0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr to_array_t</type>
      <name>to_array</name>
      <anchorfile>group__kumi__to__array.html</anchorfile>
      <anchor>ga915a6c331bad66be764b814af9f2260f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr to_record_t</type>
      <name>to_record</name>
      <anchorfile>group__kumi__to__record.html</anchorfile>
      <anchor>ga163224b58e43457f4cbc65f6817d738f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr to_ref_t</type>
      <name>to_ref</name>
      <anchorfile>group__kumi__to__ref.html</anchorfile>
      <anchor>ga271223ada5937ca2e7ea77825b89b144</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr to_tuple_t</type>
      <name>to_tuple</name>
      <anchorfile>group__kumi__to__tuple.html</anchorfile>
      <anchor>ga2642659e4d1dfee5339563fe65927385</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr transpose_t</type>
      <name>transpose</name>
      <anchorfile>group__kumi__transpose.html</anchorfile>
      <anchor>gaef527bdd76c70e7fded23a9759428f5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unique_t</type>
      <name>unique</name>
      <anchorfile>group__kumi__unique.html</anchorfile>
      <anchor>ga6479cba59ee95d4a0779e94993ab55a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr values_of_t</type>
      <name>values_of</name>
      <anchorfile>group__kumi__values__of.html</anchorfile>
      <anchor>gaa217e07b135cc3295e25689ac4ac2933</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, 1 &gt;</type>
      <name>windows</name>
      <anchorfile>group__kumi__windows.html</anchorfile>
      <anchor>gade96292292ae11da69415a778ef45ad0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_t</type>
      <name>zip</name>
      <anchorfile>group__kumi__zip.html</anchorfile>
      <anchor>ga71c21174289ba175a8d3d4b170cec05f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_max_t</type>
      <name>zip_max</name>
      <anchorfile>group__kumi__zip__max.html</anchorfile>
      <anchor>ga0ce4823febfb00cfb197f73332ba7309</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr zip_min_t</type>
      <name>zip_min</name>
      <anchorfile>group__kumi__zip__min.html</anchorfile>
      <anchor>gaf4b9aea3cee7c30fc6a516c632805423</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>array</name>
      <anchorfile>namespacekumi.html</anchorfile>
      <anchor>affc691abc76716fb35da265d80984d69</anchor>
      <arglist>() -&gt; array&lt; void, 0 &gt;</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>array</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aa65f3e4fcab288503da561d757da142c</anchor>
      <arglist>(T &amp;&amp;, Ts &amp;&amp;...) -&gt; array&lt; std::unwrap_ref_decay_t&lt; T &gt;, sizeof...(Ts)+1 &gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>adcc8d526e4d5674f453716af6cc1e5f3</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>ae8cab8261c603e758154a0239ec2613c</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;self, array&lt; U, N &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a8d1bc1c4364b25df9b0431dc7ddad7b0</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a28abb6ace51e3cd5e4a112f7716d2d21</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a44b90ef96f6acd60c54c4d67becff521</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aebb96b62c4b451b9f7dfc72843937024</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;lhs, array&lt; U, N &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a0b13841d53a273eae4e61e8637f9d094</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ab0c7a7dc02f179f880931b51d7cc53eb</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;self, record&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad8fed866ec4f0a7bec029a5caccb4d06</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aa163bc956286a74832bc716e7bdf6c8e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;self, tuple&lt; Us... &gt; const &amp;other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>ad24a079fe765887d229a4a6e2773ae93</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&lt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a6bf7895513944455a880219d7aac3fca</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7ad00985e7c37ea5a984d3aa9e51a57e</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator&gt;=</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>acfbd7477060ef62349adf34c16496e4f</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;lhs, tuple&lt; Us... &gt; const &amp;rhs) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a2a236814b119c1e3e0b1cc5ce062c282</anchor>
      <arglist>(array&lt; T, N &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>abba9991ab8e8494fb1d1a5f045d26e4c</anchor>
      <arglist>(array&lt; T, N &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>aff4433e919e93f04a68b424a83f8bffd</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1array.html</anchorfile>
      <anchor>a6252775167e7b3740075a16689c7e278</anchor>
      <arglist>(array&lt; T, N &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>record</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>ae9ac76c2474af708950b35e4b58027d6</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; record&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>abc2cd329ad25d155458850c19cc3b137</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>add6a786a9f4cf8a88d85f0b3b88d4705</anchor>
      <arglist>(record&lt; Ts... &gt; &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a275ab6e86c6128f8f5e2c30ef3f26c4f</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1record.html</anchorfile>
      <anchor>a3dc6eb9adc6e77531fe60520794558a5</anchor>
      <arglist>(record&lt; Ts... &gt; const &amp;&amp;r) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>tuple</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a612d97f050a7b0eb9999f40c045779bf</anchor>
      <arglist>(Ts &amp;&amp;...) -&gt; tuple&lt; std::unwrap_ref_decay_t&lt; Ts &gt;... &gt;</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a808bbc50bf9ed9681c41b55f5444e9ea</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>adcfd380d3fc78581e99125f49e32ae0a</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>aaea300b4c7c7cbe1103612b28ba470b5</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;arg) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7b9b1b3fbe3d201542691bee350d8a08</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a83e0ac15f8a19c27cfa885b662daed27</anchor>
      <arglist>(tuple&lt; Ts... &gt; &amp;&amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a7a96007c3fe14162df0e69e6dee3ed96</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;t) noexcept</arglist>
    </member>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>get</name>
      <anchorfile>structkumi_1_1tuple.html</anchorfile>
      <anchor>a85bd7598dcbb6464a3a89990b0e64aa4</anchor>
      <arglist>(tuple&lt; Ts... &gt; const &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>literals</name>
    <filename>namespaceliterals.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_algorithm</name>
    <title>Algorithms</title>
    <filename>group__kumi__algorithm.html</filename>
    <subgroup>kumi_reductions</subgroup>
    <subgroup>kumi_generators</subgroup>
    <subgroup>kumi_projections</subgroup>
    <subgroup>kumi_queries</subgroup>
    <subgroup>kumi_restructurings</subgroup>
    <subgroup>kumi_transforms</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_concepts</name>
    <title>Concepts</title>
    <filename>group__kumi__concepts.html</filename>
    <concept>kumi::concepts::compatible_product_types</concept>
    <concept>kumi::concepts::container</concept>
    <concept>kumi::concepts::contains_identifier</concept>
    <concept>kumi::concepts::contains_label</concept>
    <concept>kumi::concepts::contains_type</concept>
    <concept>kumi::concepts::empty_product_type</concept>
    <concept>kumi::concepts::equality_comparable</concept>
    <concept>kumi::concepts::equivalent</concept>
    <concept>kumi::concepts::field</concept>
    <concept>kumi::concepts::follows_same_semantic</concept>
    <concept>kumi::concepts::fully_named</concept>
    <concept>kumi::concepts::has_named_fields</concept>
    <concept>kumi::concepts::homogeneous_product_type</concept>
    <concept>kumi::concepts::identifier</concept>
    <concept>kumi::concepts::monoid</concept>
    <concept>kumi::concepts::non_empty_product_type</concept>
    <concept>kumi::concepts::power_type</concept>
    <concept>kumi::concepts::power_types</concept>
    <concept>kumi::concepts::product_type</concept>
    <concept>kumi::concepts::product_types</concept>
    <concept>kumi::concepts::projection</concept>
    <concept>kumi::concepts::projection_map</concept>
    <concept>kumi::concepts::queryable_by_identifier</concept>
    <concept>kumi::concepts::queryable_by_label</concept>
    <concept>kumi::concepts::queryable_by_type</concept>
    <concept>kumi::concepts::record_type</concept>
    <concept>kumi::concepts::record_types</concept>
    <concept>kumi::concepts::sized_product_type</concept>
    <concept>kumi::concepts::sized_product_type_or_more</concept>
    <concept>kumi::concepts::static_container</concept>
    <concept>kumi::concepts::uniform_product_types</concept>
    <concept>kumi::concepts::uniquely_labeled</concept>
    <concept>kumi::concepts::uniquely_named</concept>
    <concept>kumi::concepts::uniquely_typed</concept>
    <concept>kumi::concepts::unit_type</concept>
  </compound>
  <compound kind="group">
    <name>kumi_generic_transforms</name>
    <title>Element-wise Transformations</title>
    <filename>group__kumi__generic__transforms.html</filename>
    <subgroup>kumi_apply</subgroup>
    <subgroup>kumi_apply_field</subgroup>
    <subgroup>kumi_for_each</subgroup>
    <subgroup>kumi_map</subgroup>
    <subgroup>kumi_to_ref</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_record_transforms</name>
    <title>Field-wise Transformations</title>
    <filename>group__kumi__record__transforms.html</filename>
    <subgroup>kumi_for_each_field</subgroup>
    <subgroup>kumi_map_field</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_functional</name>
    <title>Functional Helpers</title>
    <filename>group__kumi__functional.html</filename>
    <subgroup>kumi_bind_back</subgroup>
    <subgroup>kumi_bind_front</subgroup>
    <subgroup>kumi_function_adjacent_index_sequence</subgroup>
    <subgroup>kumi_function_bit_and</subgroup>
    <subgroup>kumi_function_bit_or</subgroup>
    <subgroup>kumi_function_bit_xor</subgroup>
    <subgroup>kumi_function_cartesian_strides</subgroup>
    <subgroup>kumi_function_cat_index_sequence</subgroup>
    <subgroup>kumi_function_fill_index_sequence</subgroup>
    <subgroup>kumi_function_get_or</subgroup>
    <subgroup>kumi_function_indexes_for</subgroup>
    <subgroup>kumi_function_multiplies</subgroup>
    <subgroup>kumi_function_plus</subgroup>
    <subgroup>kumi_function_remove_index_sequence</subgroup>
    <subgroup>kumi_function_reverse_index_sequence</subgroup>
    <subgroup>kumi_function_rotate_index_sequence</subgroup>
    <subgroup>kumi_function_select_index_sequence</subgroup>
    <subgroup>kumi_function_shift_index_sequence</subgroup>
    <subgroup>kumi_function_size_or_v</subgroup>
    <subgroup>kumi_function_slice_index_sequence</subgroup>
    <subgroup>kumi_function_unique_index_sequence</subgroup>
    <subgroup>kumi_invoke</subgroup>
    <subgroup>kumi_invoke_r</subgroup>
    <class kind="class">kumi::function::boolean_and</class>
    <class kind="class">kumi::function::boolean_or</class>
    <class kind="class">kumi::function::boolean_xor</class>
    <class kind="class">kumi::function::foldable</class>
    <class kind="class">kumi::function::numeric_add</class>
    <class kind="class">kumi::function::numeric_prod</class>
    <class kind="class">kumi::function::scannable</class>
    <member kind="typedef">
      <type>std::remove_cvref_t&lt; decltype(kumi::function::get_or&lt; I &gt;(std::declval&lt; T &gt;(), std::declval&lt; U &gt;()))&gt;</type>
      <name>kumi::function::element_or_t</name>
      <anchorfile>group__kumi__functional.html</anchorfile>
      <anchor>ga11e943ab58829909243b4826d1f084d8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reductions</name>
    <title>Generalized Reductions</title>
    <filename>group__kumi__reductions.html</filename>
    <subgroup>kumi_bit_and</subgroup>
    <subgroup>kumi_bit_or</subgroup>
    <subgroup>kumi_bit_xor</subgroup>
    <subgroup>kumi_exclusive_scan_left</subgroup>
    <subgroup>kumi_exclusive_scan_right</subgroup>
    <subgroup>kumi_fold_left</subgroup>
    <subgroup>kumi_fold_right</subgroup>
    <subgroup>kumi_inclusive_scan_left</subgroup>
    <subgroup>kumi_inclusive_scan_right</subgroup>
    <subgroup>kumi_inner_product</subgroup>
    <subgroup>kumi_map_reduce</subgroup>
    <subgroup>kumi_max</subgroup>
    <subgroup>kumi_max_flat</subgroup>
    <subgroup>kumi_min</subgroup>
    <subgroup>kumi_min_flat</subgroup>
    <subgroup>kumi_prod</subgroup>
    <subgroup>kumi_reduce</subgroup>
    <subgroup>kumi_sum</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_generators</name>
    <title>Generators</title>
    <filename>group__kumi__generators.html</filename>
    <subgroup>kumi_fill</subgroup>
    <subgroup>kumi_generate</subgroup>
    <subgroup>kumi_iota</subgroup>
    <subgroup>kumi_member_cast</subgroup>
    <subgroup>kumi_push_back</subgroup>
    <subgroup>kumi_push_front</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_generic_traits</name>
    <title>Generic Traits</title>
    <filename>group__kumi__generic__traits.html</filename>
    <subgroup>kumi_are_uniform_product_types_v</subgroup>
    <subgroup>kumi_has_static_size_v</subgroup>
    <subgroup>kumi_is_comparable_v</subgroup>
    <subgroup>kumi_is_container_v</subgroup>
    <subgroup>kumi_is_equality_comparable_v</subgroup>
    <subgroup>kumi_is_equivalent_v</subgroup>
    <subgroup>kumi_is_ordered_v</subgroup>
    <subgroup>kumi_is_projection_map_v</subgroup>
    <subgroup>kumi_is_record_type_v</subgroup>
    <class kind="struct">kumi::apply_traits</class>
    <class kind="struct">kumi::common_product_type</class>
    <class kind="struct">kumi::map_traits</class>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::container_type_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gacf63a95bf29987c5639c10ce15e6937b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::tuple_element_t&lt; I, std::remove_cvref_t&lt; T &gt; &gt;</type>
      <name>kumi::element_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga8ba508c6d1dfb63ff6fec24deb84d66e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(get&lt; kumi_implementation_defined{}&gt;(std::declval&lt; T &amp;&amp; &gt;()))</type>
      <name>kumi::field_of_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gad4afc653b2f97e5be9ed92756cfc32ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(get&lt; I &gt;(std::declval&lt; T &amp;&amp; &gt;()))</type>
      <name>kumi::member_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaca6d42cbec766fb8d43a4060077e2624</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::stored_member_t</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga17e8e213d54b65fdd4de0ec25916d3e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::all_unique_names_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga29ec70c788b9f655ef3b0f013ad63cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::all_uniques_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga070181668492faff7e8b283ced082df3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr std::size_t</type>
      <name>kumi::container_size_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gad9f0e77ce97f1a124d20a378a8bf3c57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_instance_of_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaf70c64a5b0d21e1bcc3e51077c06d18d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_power_type_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>gaa1989d911d3452c800cd62f0c9d78607</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_product_type_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga543f9adb09ce98ab19a15e3a90c52656</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr std::size_t</type>
      <name>kumi::size_v</name>
      <anchorfile>group__kumi__generic__traits.html</anchorfile>
      <anchor>ga4dd894f30adf7e5f7ae95124f66d8adb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_index_projections</name>
    <title>Index-wise Projections</title>
    <filename>group__kumi__index__projections.html</filename>
    <subgroup>kumi_back</subgroup>
    <subgroup>kumi_extract</subgroup>
    <subgroup>kumi_front</subgroup>
    <subgroup>kumi_pop_back</subgroup>
    <subgroup>kumi_pop_front</subgroup>
    <subgroup>kumi_remove</subgroup>
    <subgroup>kumi_reorder</subgroup>
    <subgroup>kumi_reorder_fields</subgroup>
    <subgroup>kumi_reverse</subgroup>
    <subgroup>kumi_rotate_left</subgroup>
    <subgroup>kumi_rotate_right</subgroup>
    <subgroup>kumi_split</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_tuple_transforms</name>
    <title>Index-wise Transformations</title>
    <filename>group__kumi__tuple__transforms.html</filename>
    <subgroup>kumi_for_each_index</subgroup>
    <subgroup>kumi_map_index</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_details</name>
    <title>Internal Implementation Helpers</title>
    <filename>group__kumi__details.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_array_related</name>
    <title>Power Types and associated Functions</title>
    <filename>group__kumi__array__related.html</filename>
    <subgroup>kumi_forward_as_array</subgroup>
    <subgroup>kumi_from_array</subgroup>
    <subgroup>kumi_make_array</subgroup>
    <subgroup>kumi_to_array</subgroup>
    <class kind="class">kumi::array</class>
    <class kind="struct">kumi::as_array</class>
  </compound>
  <compound kind="group">
    <name>kumi_projections</name>
    <title>Projections</title>
    <filename>group__kumi__projections.html</filename>
    <subgroup>kumi_index_projections</subgroup>
    <subgroup>kumi_type_projections</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_queries</name>
    <title>Queries</title>
    <filename>group__kumi__queries.html</filename>
    <subgroup>kumi_all_of</subgroup>
    <subgroup>kumi_any_of</subgroup>
    <subgroup>kumi_contains</subgroup>
    <subgroup>kumi_contains_any</subgroup>
    <subgroup>kumi_contains_none</subgroup>
    <subgroup>kumi_contains_only</subgroup>
    <subgroup>kumi_count</subgroup>
    <subgroup>kumi_count_if</subgroup>
    <subgroup>kumi_locate</subgroup>
    <subgroup>kumi_none_of</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_record_traits</name>
    <title>Record Related Traits</title>
    <filename>group__kumi__record__traits.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::stored_element_t</name>
      <anchorfile>group__kumi__record__traits.html</anchorfile>
      <anchor>gaa957535657d5741421f09c44c5faaa62</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_record_related</name>
    <title>Record Types and associated Functions</title>
    <filename>group__kumi__record__related.html</filename>
    <subgroup>kumi_forward_as_record</subgroup>
    <subgroup>kumi_from_record</subgroup>
    <subgroup>kumi_make_record</subgroup>
    <subgroup>kumi_to_record</subgroup>
    <class kind="class">kumi::record</class>
    <member kind="variable">
      <type>constexpr tie_as_record_t&lt; Fields... &gt;</type>
      <name>kumi::tie_as_record</name>
      <anchorfile>group__kumi__record__related.html</anchorfile>
      <anchor>ga45b4db8f009ab12f62d938338d29d536</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_restructurings</name>
    <title>Restructurings</title>
    <filename>group__kumi__restructurings.html</filename>
    <subgroup>kumi_as_flat_ptr</subgroup>
    <subgroup>kumi_cartesian_product</subgroup>
    <subgroup>kumi_cat</subgroup>
    <subgroup>kumi_chunks</subgroup>
    <subgroup>kumi_compress</subgroup>
    <subgroup>kumi_flatten</subgroup>
    <subgroup>kumi_flatten_all</subgroup>
    <subgroup>kumi_reindex</subgroup>
    <subgroup>kumi_tiles</subgroup>
    <subgroup>kumi_transpose</subgroup>
    <subgroup>kumi_windows</subgroup>
    <subgroup>kumi_zip</subgroup>
    <subgroup>kumi_zip_max</subgroup>
    <subgroup>kumi_zip_min</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_traits</name>
    <title>Traits</title>
    <filename>group__kumi__traits.html</filename>
    <subgroup>kumi_generic_traits</subgroup>
    <subgroup>kumi_record_traits</subgroup>
    <subgroup>kumi_tuple_traits</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_transforms</name>
    <title>Transformations</title>
    <filename>group__kumi__transforms.html</filename>
    <subgroup>kumi_generic_transforms</subgroup>
    <subgroup>kumi_record_transforms</subgroup>
    <subgroup>kumi_tuple_transforms</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_tuple_traits</name>
    <title>Tuple Related Traits</title>
    <filename>group__kumi__tuple__traits.html</filename>
    <subgroup>kumi_is_homogeneous_v</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_tuple_related</name>
    <title>Tuple Types and associated Functions</title>
    <filename>group__kumi__tuple__related.html</filename>
    <subgroup>kumi_forward_as_tuple</subgroup>
    <subgroup>kumi_from_tuple</subgroup>
    <subgroup>kumi_make_tuple</subgroup>
    <subgroup>kumi_tie</subgroup>
    <subgroup>kumi_to_tuple</subgroup>
    <class kind="struct">kumi::as_tuple</class>
    <class kind="class">kumi::tuple</class>
  </compound>
  <compound kind="group">
    <name>kumi_type_projections</name>
    <title>Type-wise Projections</title>
    <filename>group__kumi__type__projections.html</filename>
    <subgroup>kumi_all_unique</subgroup>
    <subgroup>kumi_filter</subgroup>
    <subgroup>kumi_filter_not</subgroup>
    <subgroup>kumi_partition</subgroup>
    <subgroup>kumi_unique</subgroup>
  </compound>
  <compound kind="group">
    <name>kumi_utility</name>
    <title>Utility Types and Functions</title>
    <filename>group__kumi__utility.html</filename>
    <subgroup>kumi_capture_field</subgroup>
    <subgroup>kumi_field_cast</subgroup>
    <subgroup>kumi_field_value_of</subgroup>
    <subgroup>kumi_get_index_of_field</subgroup>
    <subgroup>kumi_get_index_of_label</subgroup>
    <subgroup>kumi_get_index_of_type</subgroup>
    <subgroup>kumi_identifier_of</subgroup>
    <subgroup>kumi_identifiers</subgroup>
    <subgroup>kumi_index</subgroup>
    <subgroup>kumi_indexes</subgroup>
    <subgroup>kumi_label</subgroup>
    <subgroup>kumi_label_of</subgroup>
    <subgroup>kumi_make_indexes</subgroup>
    <subgroup>kumi_members_of</subgroup>
    <subgroup>kumi_none</subgroup>
    <subgroup>kumi_only</subgroup>
    <subgroup>kumi_projection_map</subgroup>
    <subgroup>kumi_values_of</subgroup>
    <class kind="class">kumi::as</class>
    <class kind="class">kumi::builder</class>
    <class kind="class">kumi::field</class>
    <class kind="class">kumi::identifier</class>
    <class kind="class">kumi::index_t</class>
    <class kind="class">kumi::label_t</class>
    <class kind="class">kumi::name</class>
    <class kind="class">kumi::projection_map</class>
    <class kind="class">kumi::str</class>
    <class kind="class">kumi::unit</class>
    <class kind="class">kumi::unknown</class>
    <member kind="function">
      <type>auto</type>
      <name>as_streamable</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>gae8a72b55c5e0a89b70663342e2c36eaf</anchor>
      <arglist>(auto e)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_c</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga60825dffaa5ee2c50e1d1a24057bdcf1</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_id</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga10f2338fc8867a50a4295325873f3de4</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::literals::operator&quot;&quot;_l</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga1eb529eb7ccadf0b5e632c132c2b9750</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::predicate</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga9c8c29e8a2f4f5e8a663200559fdc983</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>kumi::str constexpr</type>
      <name>to_str</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>gaf4584fa9d1d39f32081265df16e00364</anchor>
      <arglist>(auto e)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field::operator&lt;&lt;</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
    <member kind="friend">
      <type>friend std::basic_ostream&lt; CharT, Traits &gt; &amp;</type>
      <name>kumi::field&lt; Id, T &gt;::operator&lt;&lt;</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>ga34969da06ac58348bc220ebf522233f1</anchor>
      <arglist>(std::basic_ostream&lt; CharT, Traits &gt; &amp;os, field const &amp;w) noexcept</arglist>
    </member>
    <member kind="variable">
      <type>constexpr traits_check&lt; Traits &gt;</type>
      <name>kumi::if_</name>
      <anchorfile>group__kumi__utility.html</anchorfile>
      <anchor>gacadc026868e6654e80c57432643c804a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_all_of</name>
    <title>kumi::all_of</title>
    <filename>group__kumi__all__of.html</filename>
    <member kind="variable">
      <type>constexpr all_of_t</type>
      <name>kumi::all_of</name>
      <anchorfile>group__kumi__all__of.html</anchorfile>
      <anchor>gaffdb8063b72f079107cd8a7e293ba298</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_all_unique</name>
    <title>kumi::all_unique</title>
    <filename>group__kumi__all__unique.html</filename>
    <member kind="variable">
      <type>constexpr all_unique_t</type>
      <name>kumi::all_unique</name>
      <anchorfile>group__kumi__all__unique.html</anchorfile>
      <anchor>ga71bbbe8da94919e242bd3ded80ab6776</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_any_of</name>
    <title>kumi::any_of</title>
    <filename>group__kumi__any__of.html</filename>
    <member kind="variable">
      <type>constexpr any_of_t</type>
      <name>kumi::any_of</name>
      <anchorfile>group__kumi__any__of.html</anchorfile>
      <anchor>ga79566892f932a2308e23b5f21b95086f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_apply</name>
    <title>kumi::apply</title>
    <filename>group__kumi__apply.html</filename>
    <member kind="variable">
      <type>constexpr apply_t</type>
      <name>kumi::apply</name>
      <anchorfile>group__kumi__apply.html</anchorfile>
      <anchor>ga4c69a49971100b7bc9c7effd7c43f191</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_apply_field</name>
    <title>kumi::apply_field</title>
    <filename>group__kumi__apply__field.html</filename>
    <member kind="variable">
      <type>constexpr apply_field_t</type>
      <name>kumi::apply_field</name>
      <anchorfile>group__kumi__apply__field.html</anchorfile>
      <anchor>ga992364930a4a5a5b64b26730773536ab</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_are_uniform_product_types_v</name>
    <title>kumi::are_uniform_product_types_v</title>
    <filename>group__kumi__are__uniform__product__types__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::are_uniform_product_types_v</name>
      <anchorfile>group__kumi__are__uniform__product__types__v.html</anchorfile>
      <anchor>ga8a470806958b269680709330b608b042</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_as_flat_ptr</name>
    <title>kumi::as_flat_ptr</title>
    <filename>group__kumi__as__flat__ptr.html</filename>
    <member kind="variable">
      <type>constexpr as_flat_ptr_t</type>
      <name>kumi::as_flat_ptr</name>
      <anchorfile>group__kumi__as__flat__ptr.html</anchorfile>
      <anchor>ga6368952a2f6a506de75aa0e01569eab6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_back</name>
    <title>kumi::back</title>
    <filename>group__kumi__back.html</filename>
    <member kind="variable">
      <type>constexpr back_t</type>
      <name>kumi::back</name>
      <anchorfile>group__kumi__back.html</anchorfile>
      <anchor>gae635e0c094282372ff5393840b6f52c2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_bind_back</name>
    <title>kumi::bind_back</title>
    <filename>group__kumi__bind__back.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bind_back</name>
      <anchorfile>group__kumi__bind__back.html</anchorfile>
      <anchor>ga02fbf71873458cc8a364a7f6efcfadf2</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_bind_front</name>
    <title>kumi::bind_front</title>
    <filename>group__kumi__bind__front.html</filename>
    <member kind="function">
      <type>constexpr auto</type>
      <name>kumi::bind_front</name>
      <anchorfile>group__kumi__bind__front.html</anchorfile>
      <anchor>ga08c383ce2fb100dda15baf96b4e60d2f</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; C &gt; &gt; &amp;&amp;(std::is_nothrow_move_constructible_v&lt; std::decay_t&lt; Ts &gt; &gt; &amp;&amp;...))</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_bit_and</name>
    <title>kumi::bit_and</title>
    <filename>group__kumi__bit__and.html</filename>
    <member kind="variable">
      <type>constexpr bit_and_t</type>
      <name>kumi::bit_and</name>
      <anchorfile>group__kumi__bit__and.html</anchorfile>
      <anchor>ga17c3d8bab8099c4756a8b6fb4e9d4380</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_bit_or</name>
    <title>kumi::bit_or</title>
    <filename>group__kumi__bit__or.html</filename>
    <member kind="variable">
      <type>constexpr bit_or_t</type>
      <name>kumi::bit_or</name>
      <anchorfile>group__kumi__bit__or.html</anchorfile>
      <anchor>ga74fa99e87e80d8bb15ea6694e381bd49</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_bit_xor</name>
    <title>kumi::bit_xor</title>
    <filename>group__kumi__bit__xor.html</filename>
    <member kind="variable">
      <type>constexpr bit_xor_t</type>
      <name>kumi::bit_xor</name>
      <anchorfile>group__kumi__bit__xor.html</anchorfile>
      <anchor>ga2797c81f32afec2f2ce4856a5155807c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_capture_field</name>
    <title>kumi::capture_field</title>
    <filename>group__kumi__capture__field.html</filename>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::capture_field</name>
      <anchorfile>group__kumi__capture__field.html</anchorfile>
      <anchor>gafc8e80ba53336a0142f3267959c1ba71</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_cartesian_product</name>
    <title>kumi::cartesian_product</title>
    <filename>group__kumi__cartesian__product.html</filename>
    <member kind="variable">
      <type>constexpr cartesian_product_t</type>
      <name>kumi::cartesian_product</name>
      <anchorfile>group__kumi__cartesian__product.html</anchorfile>
      <anchor>ga39128fad2c11b9fea55558222a87721c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_cat</name>
    <title>kumi::cat</title>
    <filename>group__kumi__cat.html</filename>
    <member kind="variable">
      <type>constexpr cat_t</type>
      <name>kumi::cat</name>
      <anchorfile>group__kumi__cat.html</anchorfile>
      <anchor>ga4550222df58187f71b1b1347500e324a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_chunks</name>
    <title>kumi::chunks</title>
    <filename>group__kumi__chunks.html</filename>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, N &gt;</type>
      <name>kumi::chunks</name>
      <anchorfile>group__kumi__chunks.html</anchorfile>
      <anchor>gaf4b0bcda72790c2ac55519adaf89456e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_compress</name>
    <title>kumi::compress</title>
    <filename>group__kumi__compress.html</filename>
    <member kind="variable">
      <type>constexpr compress_t</type>
      <name>kumi::compress</name>
      <anchorfile>group__kumi__compress.html</anchorfile>
      <anchor>gaa9d6196838118af0a837160d8bbf532c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_contains</name>
    <title>kumi::contains</title>
    <filename>group__kumi__contains.html</filename>
    <member kind="variable">
      <type>constexpr contains_t</type>
      <name>kumi::contains</name>
      <anchorfile>group__kumi__contains.html</anchorfile>
      <anchor>ga3a9b6e2d0fbdace9e57b3846d24a3b57</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_contains_any</name>
    <title>kumi::contains_any</title>
    <filename>group__kumi__contains__any.html</filename>
    <member kind="variable">
      <type>constexpr contains_any_t</type>
      <name>kumi::contains_any</name>
      <anchorfile>group__kumi__contains__any.html</anchorfile>
      <anchor>ga639f59cb294f670d2f2c468c4ef204d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_contains_none</name>
    <title>kumi::contains_none</title>
    <filename>group__kumi__contains__none.html</filename>
    <member kind="variable">
      <type>constexpr contains_none_t</type>
      <name>kumi::contains_none</name>
      <anchorfile>group__kumi__contains__none.html</anchorfile>
      <anchor>ga7b1bbe80c513abfdedd1196f027601d2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_contains_only</name>
    <title>kumi::contains_only</title>
    <filename>group__kumi__contains__only.html</filename>
    <member kind="variable">
      <type>constexpr contains_only_t</type>
      <name>kumi::contains_only</name>
      <anchorfile>group__kumi__contains__only.html</anchorfile>
      <anchor>ga36431211bf121466392b290459a45498</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_count</name>
    <title>kumi::count</title>
    <filename>group__kumi__count.html</filename>
    <member kind="variable">
      <type>constexpr count_t</type>
      <name>kumi::count</name>
      <anchorfile>group__kumi__count.html</anchorfile>
      <anchor>ga8240f113b5feb1dcc826949f28f17a47</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_count_if</name>
    <title>kumi::count_if</title>
    <filename>group__kumi__count__if.html</filename>
    <member kind="variable">
      <type>constexpr count_if_t</type>
      <name>kumi::count_if</name>
      <anchorfile>group__kumi__count__if.html</anchorfile>
      <anchor>gaec0fb27dc2250b97648bc52b8e83b561</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_exclusive_scan_left</name>
    <title>kumi::exclusive_scan_left</title>
    <filename>group__kumi__exclusive__scan__left.html</filename>
    <member kind="variable">
      <type>constexpr exclusive_scan_left_t</type>
      <name>kumi::exclusive_scan_left</name>
      <anchorfile>group__kumi__exclusive__scan__left.html</anchorfile>
      <anchor>ga529950ddf6573473b2f9b7ec886c61f9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_exclusive_scan_right</name>
    <title>kumi::exclusive_scan_right</title>
    <filename>group__kumi__exclusive__scan__right.html</filename>
    <member kind="variable">
      <type>constexpr exclusive_scan_right_t</type>
      <name>kumi::exclusive_scan_right</name>
      <anchorfile>group__kumi__exclusive__scan__right.html</anchorfile>
      <anchor>gaa66bb36d76db2d7854196bc156fb35c2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_extract</name>
    <title>kumi::extract</title>
    <filename>group__kumi__extract.html</filename>
    <member kind="variable">
      <type>constexpr extract_t</type>
      <name>kumi::extract</name>
      <anchorfile>group__kumi__extract.html</anchorfile>
      <anchor>ga1a7617bafd6f8598cca8e7e6a5c6f383</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_field_cast</name>
    <title>kumi::field_cast</title>
    <filename>group__kumi__field__cast.html</filename>
    <member kind="function">
      <type>decltype(auto) constexpr</type>
      <name>kumi::field::field_cast</name>
      <anchorfile>group__kumi__field__cast.html</anchorfile>
      <anchor>ga59477c1d8542af2601f493e3320434ee</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_field_value_of</name>
    <title>kumi::field_value_of</title>
    <filename>group__kumi__field__value__of.html</filename>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::field_value_of</name>
      <anchorfile>group__kumi__field__value__of.html</anchorfile>
      <anchor>gabf2013046cf8ec8ac781128a815709cc</anchor>
      <arglist>(T &amp;&amp;t) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_fill</name>
    <title>kumi::fill</title>
    <filename>group__kumi__fill.html</filename>
    <member kind="variable">
      <type>constexpr fill_t&lt; N &gt;</type>
      <name>kumi::fill</name>
      <anchorfile>group__kumi__fill.html</anchorfile>
      <anchor>gafd5d1c6d3d2fcb3c424826b8bddb8b0a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_filter</name>
    <title>kumi::filter</title>
    <filename>group__kumi__filter.html</filename>
    <member kind="variable">
      <type>constexpr filter_t&lt; Pred &gt;</type>
      <name>kumi::filter</name>
      <anchorfile>group__kumi__filter.html</anchorfile>
      <anchor>ga2c9b5ff6b698c7dcb0feb2da1679fa9b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_filter_not</name>
    <title>kumi::filter_not</title>
    <filename>group__kumi__filter__not.html</filename>
    <member kind="variable">
      <type>constexpr filter_not_t&lt; Pred &gt;</type>
      <name>kumi::filter_not</name>
      <anchorfile>group__kumi__filter__not.html</anchorfile>
      <anchor>ga750bc3d3425c955e1be6ef1b3879c314</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_flatten</name>
    <title>kumi::flatten</title>
    <filename>group__kumi__flatten.html</filename>
    <member kind="variable">
      <type>constexpr flatten_t</type>
      <name>kumi::flatten</name>
      <anchorfile>group__kumi__flatten.html</anchorfile>
      <anchor>ga49acccc42ec8af7b96b63e8f38796df2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_flatten_all</name>
    <title>kumi::flatten_all</title>
    <filename>group__kumi__flatten__all.html</filename>
    <member kind="variable">
      <type>constexpr flatten_all_t</type>
      <name>kumi::flatten_all</name>
      <anchorfile>group__kumi__flatten__all.html</anchorfile>
      <anchor>gaa780fd338fb61c86f226ae05adfaf426</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_fold_left</name>
    <title>kumi::fold_left</title>
    <filename>group__kumi__fold__left.html</filename>
    <member kind="variable">
      <type>constexpr fold_left_t</type>
      <name>kumi::fold_left</name>
      <anchorfile>group__kumi__fold__left.html</anchorfile>
      <anchor>gac7fc6bc4e0aff96cca71f0a64b0f2aa1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_fold_right</name>
    <title>kumi::fold_right</title>
    <filename>group__kumi__fold__right.html</filename>
    <member kind="variable">
      <type>constexpr fold_right_t</type>
      <name>kumi::fold_right</name>
      <anchorfile>group__kumi__fold__right.html</anchorfile>
      <anchor>gaee418c18e09e3b1789c23ec00681db42</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_for_each</name>
    <title>kumi::for_each</title>
    <filename>group__kumi__for__each.html</filename>
    <member kind="variable">
      <type>constexpr for_each_t</type>
      <name>kumi::for_each</name>
      <anchorfile>group__kumi__for__each.html</anchorfile>
      <anchor>ga58c4bb5e62083b4b37396d39c6446164</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_for_each_field</name>
    <title>kumi::for_each_field</title>
    <filename>group__kumi__for__each__field.html</filename>
    <member kind="variable">
      <type>constexpr for_each_field_t</type>
      <name>kumi::for_each_field</name>
      <anchorfile>group__kumi__for__each__field.html</anchorfile>
      <anchor>gafb2ad3366fa0af8cb1f3c32cb6c6970d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_for_each_index</name>
    <title>kumi::for_each_index</title>
    <filename>group__kumi__for__each__index.html</filename>
    <member kind="variable">
      <type>constexpr for_each_index_t</type>
      <name>kumi::for_each_index</name>
      <anchorfile>group__kumi__for__each__index.html</anchorfile>
      <anchor>ga34623706699cbbd62d626e3cc49aa8dc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_forward_as_array</name>
    <title>kumi::forward_as_array</title>
    <filename>group__kumi__forward__as__array.html</filename>
    <member kind="variable">
      <type>constexpr forward_as_array_t</type>
      <name>kumi::forward_as_array</name>
      <anchorfile>group__kumi__forward__as__array.html</anchorfile>
      <anchor>gaa93098695e1bc5a6db9572a70b5a2cd8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_forward_as_record</name>
    <title>kumi::forward_as_record</title>
    <filename>group__kumi__forward__as__record.html</filename>
    <member kind="variable">
      <type>constexpr forward_as_record_t&lt; Fields... &gt;</type>
      <name>kumi::forward_as_record</name>
      <anchorfile>group__kumi__forward__as__record.html</anchorfile>
      <anchor>gacfd38acd9ecb27bff2bb2ad0f885e326</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_forward_as_tuple</name>
    <title>kumi::forward_as_tuple</title>
    <filename>group__kumi__forward__as__tuple.html</filename>
    <member kind="variable">
      <type>constexpr forward_as_tuple_t</type>
      <name>kumi::forward_as_tuple</name>
      <anchorfile>group__kumi__forward__as__tuple.html</anchorfile>
      <anchor>ga934bd052835c7cc48a870fbc7c86e6ac</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_from_array</name>
    <title>kumi::from_array</title>
    <filename>group__kumi__from__array.html</filename>
    <member kind="variable">
      <type>constexpr from_array_t&lt; Type &gt;</type>
      <name>kumi::from_array</name>
      <anchorfile>group__kumi__from__array.html</anchorfile>
      <anchor>gaca20d574b6dd574d6628fae65ea688fe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_from_record</name>
    <title>kumi::from_record</title>
    <filename>group__kumi__from__record.html</filename>
    <member kind="variable">
      <type>constexpr from_record_t&lt; Type &gt;</type>
      <name>kumi::from_record</name>
      <anchorfile>group__kumi__from__record.html</anchorfile>
      <anchor>gae4456196aadb75484ad0b061c83b3f95</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_from_tuple</name>
    <title>kumi::from_tuple</title>
    <filename>group__kumi__from__tuple.html</filename>
    <member kind="variable">
      <type>constexpr from_tuple_t&lt; Type &gt;</type>
      <name>kumi::from_tuple</name>
      <anchorfile>group__kumi__from__tuple.html</anchorfile>
      <anchor>gaebb54917d0e966b2f64aaa91dedcd5dc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_front</name>
    <title>kumi::front</title>
    <filename>group__kumi__front.html</filename>
    <member kind="variable">
      <type>constexpr front_t</type>
      <name>kumi::front</name>
      <anchorfile>group__kumi__front.html</anchorfile>
      <anchor>gaa1618c96c4c7003afeccfb19e25b35bb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_adjacent_index_sequence</name>
    <title>kumi::function::adjacent_index_sequence</title>
    <filename>group__kumi__function__adjacent__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::adjacent_index_sequence</name>
      <anchorfile>group__kumi__function__adjacent__index__sequence.html</anchorfile>
      <anchor>gae8a54a1753591f4aa7594a1f419072c6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_bit_and</name>
    <title>kumi::function::bit_and</title>
    <filename>group__kumi__function__bit__and.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_function_bit_or</name>
    <title>kumi::function::bit_or</title>
    <filename>group__kumi__function__bit__or.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_function_bit_xor</name>
    <title>kumi::function::bit_xor</title>
    <filename>group__kumi__function__bit__xor.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_function_cartesian_strides</name>
    <title>kumi::function::cartesian_strides</title>
    <filename>group__kumi__function__cartesian__strides.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::cartesian_strides</name>
      <anchorfile>group__kumi__function__cartesian__strides.html</anchorfile>
      <anchor>gac3dc3023ed46df23816b0c0bfd4817dd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_cat_index_sequence</name>
    <title>kumi::function::cat_index_sequence</title>
    <filename>group__kumi__function__cat__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::cat_index_sequence</name>
      <anchorfile>group__kumi__function__cat__index__sequence.html</anchorfile>
      <anchor>ga87c3ce71d1306bbe56aa7dd6bb789b5d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_fill_index_sequence</name>
    <title>kumi::function::fill_index_sequence</title>
    <filename>group__kumi__function__fill__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::fill_index_sequence</name>
      <anchorfile>group__kumi__function__fill__index__sequence.html</anchorfile>
      <anchor>ga8f23bb9bd9817ad2d807854bad64897c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_get_or</name>
    <title>kumi::function::get_or</title>
    <filename>group__kumi__function__get__or.html</filename>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::function::get_or</name>
      <anchorfile>group__kumi__function__get__or.html</anchorfile>
      <anchor>ga42064b97f063feae3d934bd111ef74ec</anchor>
      <arglist>(T &amp;&amp;t, V &amp;&amp;v)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_indexes_for</name>
    <title>kumi::function::indexes_for</title>
    <filename>group__kumi__function__indexes__for.html</filename>
    <member kind="typedef">
      <type>std::make_index_sequence&lt; kumi::size_v&lt; T &gt; &gt;</type>
      <name>kumi::function::indexes_for</name>
      <anchorfile>group__kumi__function__indexes__for.html</anchorfile>
      <anchor>ga31ec47f07956e9676243754c7ccd6227</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_multiplies</name>
    <title>kumi::function::multiplies</title>
    <filename>group__kumi__function__multiplies.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_function_plus</name>
    <title>kumi::function::plus</title>
    <filename>group__kumi__function__plus.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_function_remove_index_sequence</name>
    <title>kumi::function::remove_index_sequence</title>
    <filename>group__kumi__function__remove__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined B) ?(E - B+S - 1)/S :0), std::make_index_sequence&lt; N -((E &gt; B) ?(E - B+S - 1)/S :0)&gt; &gt;)</type>
      <name>kumi::function::remove_index_sequence</name>
      <anchorfile>group__kumi__function__remove__index__sequence.html</anchorfile>
      <anchor>gaab08a06ed8795bacdf72336cf06b0e6a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_reverse_index_sequence</name>
    <title>kumi::function::reverse_index_sequence</title>
    <filename>group__kumi__function__reverse__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::reverse_index_sequence</name>
      <anchorfile>group__kumi__function__reverse__index__sequence.html</anchorfile>
      <anchor>ga885127642ae710479faebf90f37ba6b8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_rotate_index_sequence</name>
    <title>kumi::function::rotate_index_sequence</title>
    <filename>group__kumi__function__rotate__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::rotate_index_sequence</name>
      <anchorfile>group__kumi__function__rotate__index__sequence.html</anchorfile>
      <anchor>gaf80ca8e67a8eec3669b6e67c1a3c09ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_select_index_sequence</name>
    <title>kumi::function::select_index_sequence</title>
    <filename>group__kumi__function__select__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::select_index_sequence</name>
      <anchorfile>group__kumi__function__select__index__sequence.html</anchorfile>
      <anchor>gab3c7eda04b7101058c5bcf5bbda210b6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_shift_index_sequence</name>
    <title>kumi::function::shift_index_sequence</title>
    <filename>group__kumi__function__shift__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::shift_index_sequence</name>
      <anchorfile>group__kumi__function__shift__index__sequence.html</anchorfile>
      <anchor>gaa7eb75e2ab9dc4f4018674527cff23e1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_size_or_v</name>
    <title>kumi::function::size_or_v</title>
    <filename>group__kumi__function__size__or__v.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>kumi::function::size_or_v</name>
      <anchorfile>group__kumi__function__size__or__v.html</anchorfile>
      <anchor>ga1aeb494d781c6a1d8f48168f4f093afe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_slice_index_sequence</name>
    <title>kumi::function::slice_index_sequence</title>
    <filename>group__kumi__function__slice__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined &gt;)</type>
      <name>kumi::function::slice_index_sequence</name>
      <anchorfile>group__kumi__function__slice__index__sequence.html</anchorfile>
      <anchor>gab5f7e8b998190a1b17109811a279a6d6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_function_unique_index_sequence</name>
    <title>kumi::function::unique_index_sequence</title>
    <filename>group__kumi__function__unique__index__sequence.html</filename>
    <member kind="typedef">
      <type>decltype(kumi_implementation_defined)</type>
      <name>kumi::function::unique_index_sequence</name>
      <anchorfile>group__kumi__function__unique__index__sequence.html</anchorfile>
      <anchor>ga41fc6fa7af3a69b712e76929faa994d5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_generate</name>
    <title>kumi::generate</title>
    <filename>group__kumi__generate.html</filename>
    <member kind="variable">
      <type>constexpr generate_t&lt; N &gt;</type>
      <name>kumi::generate</name>
      <anchorfile>group__kumi__generate.html</anchorfile>
      <anchor>gaba2efbda8df6baaccd4e35343d70163f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_get_index_of_field</name>
    <title>kumi::get_index_of_field</title>
    <filename>group__kumi__get__index__of__field.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_field</name>
      <anchorfile>group__kumi__get__index__of__field.html</anchorfile>
      <anchor>ga2fc46ed70d43d14ca52860896fd1e364</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_get_index_of_label</name>
    <title>kumi::get_index_of_label</title>
    <filename>group__kumi__get__index__of__label.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_label</name>
      <anchorfile>group__kumi__get__index__of__label.html</anchorfile>
      <anchor>ga6c5b5c12c2baa75189a7d94e55fbfe17</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_get_index_of_type</name>
    <title>kumi::get_index_of_type</title>
    <filename>group__kumi__get__index__of__type.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::get_index_of_type</name>
      <anchorfile>group__kumi__get__index__of__type.html</anchorfile>
      <anchor>ga15172fcc47fe0c88931be39b9c3633fd</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_has_static_size_v</name>
    <title>kumi::has_static_size_v</title>
    <filename>group__kumi__has__static__size__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::has_static_size_v</name>
      <anchorfile>group__kumi__has__static__size__v.html</anchorfile>
      <anchor>gaaaac9da4c0098fbf974cd6917827dae4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_identifier_of</name>
    <title>kumi::identifier_of</title>
    <filename>group__kumi__identifier__of.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::identifier_of</name>
      <anchorfile>group__kumi__identifier__of.html</anchorfile>
      <anchor>gab3919ec6f8098dd1fdafe9c3a79ef0dc</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_identifiers</name>
    <title>kumi::identifiers</title>
    <filename>group__kumi__identifiers.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::identifiers</name>
      <anchorfile>group__kumi__identifiers.html</anchorfile>
      <anchor>ga63a205c6c2502e733987043857abea05</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_inclusive_scan_left</name>
    <title>kumi::inclusive_scan_left</title>
    <filename>group__kumi__inclusive__scan__left.html</filename>
    <member kind="variable">
      <type>constexpr inclusive_scan_left_t</type>
      <name>kumi::inclusive_scan_left</name>
      <anchorfile>group__kumi__inclusive__scan__left.html</anchorfile>
      <anchor>ga1389eee6fb884b34ed4957884ecd39a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_inclusive_scan_right</name>
    <title>kumi::inclusive_scan_right</title>
    <filename>group__kumi__inclusive__scan__right.html</filename>
    <member kind="variable">
      <type>constexpr inclusive_scan_right_t</type>
      <name>kumi::inclusive_scan_right</name>
      <anchorfile>group__kumi__inclusive__scan__right.html</anchorfile>
      <anchor>gab55848ee4bd1b0cc0f22015a2bac5047</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_index</name>
    <title>kumi::index</title>
    <filename>group__kumi__index.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_indexes</name>
    <title>kumi::indexes</title>
    <filename>group__kumi__indexes.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::indexes</name>
      <anchorfile>group__kumi__indexes.html</anchorfile>
      <anchor>ga6882a4ada4935fa0fd4ef32ce3716ffb</anchor>
      <arglist>(Ts...) noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_inner_product</name>
    <title>kumi::inner_product</title>
    <filename>group__kumi__inner__product.html</filename>
    <member kind="variable">
      <type>constexpr inner_product_t</type>
      <name>kumi::inner_product</name>
      <anchorfile>group__kumi__inner__product.html</anchorfile>
      <anchor>ga712c681a51bdbc86d41b160deddd2e1d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_invoke</name>
    <title>kumi::invoke</title>
    <filename>group__kumi__invoke.html</filename>
    <member kind="function">
      <type>constexpr decltype(auto)</type>
      <name>kumi::invoke</name>
      <anchorfile>group__kumi__invoke.html</anchorfile>
      <anchor>gace270cfbaa7b0d519fdf03f8225f2908</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_invoke_r</name>
    <title>kumi::invoke_r</title>
    <filename>group__kumi__invoke__r.html</filename>
    <member kind="function">
      <type>constexpr R</type>
      <name>kumi::invoke_r</name>
      <anchorfile>group__kumi__invoke__r.html</anchorfile>
      <anchor>ga2ad666793ad04ea9b66c84b83f41f375</anchor>
      <arglist>(C &amp;&amp;c, Ts &amp;&amp;... ts) noexcept(std::is_nothrow_invocable_r_v&lt; R, C, Ts... &gt;)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_iota</name>
    <title>kumi::iota</title>
    <filename>group__kumi__iota.html</filename>
    <member kind="variable">
      <type>constexpr iota_t&lt; N &gt;</type>
      <name>kumi::iota</name>
      <anchorfile>group__kumi__iota.html</anchorfile>
      <anchor>gace6e022bb94a706731299b9d395ac10d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_comparable_v</name>
    <title>kumi::is_comparable_v</title>
    <filename>group__kumi__is__comparable__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_comparable_v</name>
      <anchorfile>group__kumi__is__comparable__v.html</anchorfile>
      <anchor>ga02be876fed0356a37924a4df900feace</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_container_v</name>
    <title>kumi::is_container_v</title>
    <filename>group__kumi__is__container__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_container_v</name>
      <anchorfile>group__kumi__is__container__v.html</anchorfile>
      <anchor>ga02b588394b12893e71b1d6162db0b4b4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_equality_comparable_v</name>
    <title>kumi::is_equality_comparable_v</title>
    <filename>group__kumi__is__equality__comparable__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_equality_comparable_v</name>
      <anchorfile>group__kumi__is__equality__comparable__v.html</anchorfile>
      <anchor>ga156cb23641777bc9b29e3d3cff87aba4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_equivalent_v</name>
    <title>kumi::is_equivalent_v</title>
    <filename>group__kumi__is__equivalent__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_equivalent_v</name>
      <anchorfile>group__kumi__is__equivalent__v.html</anchorfile>
      <anchor>ga65a2b6e28cd4ab58cfaffd90fea1b215</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_homogeneous_v</name>
    <title>kumi::is_homogeneous_v</title>
    <filename>group__kumi__is__homogeneous__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_homogeneous_v</name>
      <anchorfile>group__kumi__is__homogeneous__v.html</anchorfile>
      <anchor>ga444ecc58235c6cb4f805f5bb03409e4c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_ordered_v</name>
    <title>kumi::is_ordered_v</title>
    <filename>group__kumi__is__ordered__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_ordered_v</name>
      <anchorfile>group__kumi__is__ordered__v.html</anchorfile>
      <anchor>ga88b0cafd09ba2a1bbc6e301f70d9ba17</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_projection_map_v</name>
    <title>kumi::is_projection_map_v</title>
    <filename>group__kumi__is__projection__map__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_projection_map_v</name>
      <anchorfile>group__kumi__is__projection__map__v.html</anchorfile>
      <anchor>gac535fd8eadc87407e3132a7fceda4ab1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_is_record_type_v</name>
    <title>kumi::is_record_type_v</title>
    <filename>group__kumi__is__record__type__v.html</filename>
    <member kind="variable">
      <type>constexpr bool</type>
      <name>kumi::is_record_type_v</name>
      <anchorfile>group__kumi__is__record__type__v.html</anchorfile>
      <anchor>ga75612200d87c3aa30f068205aa882e2a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_label</name>
    <title>kumi::label</title>
    <filename>group__kumi__label.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_label_of</name>
    <title>kumi::label_of</title>
    <filename>group__kumi__label__of.html</filename>
    <member kind="function">
      <type>consteval kumi_implementation_defined auto</type>
      <name>kumi::label_of</name>
      <anchorfile>group__kumi__label__of.html</anchorfile>
      <anchor>ga83a3a02d003803934382a94c4f126264</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_locate</name>
    <title>kumi::locate</title>
    <filename>group__kumi__locate.html</filename>
    <member kind="variable">
      <type>constexpr locate_t</type>
      <name>kumi::locate</name>
      <anchorfile>group__kumi__locate.html</anchorfile>
      <anchor>ga39f807d6c2b8909a712d431acde4153e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_make_array</name>
    <title>kumi::make_array</title>
    <filename>group__kumi__make__array.html</filename>
    <member kind="variable">
      <type>constexpr make_array_t</type>
      <name>kumi::make_array</name>
      <anchorfile>group__kumi__make__array.html</anchorfile>
      <anchor>ga1f35cbd4396ea2b88d6c34f63c02c8c6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_make_indexes</name>
    <title>kumi::make_indexes</title>
    <filename>group__kumi__make__indexes.html</filename>
    <member kind="function">
      <type>consteval auto</type>
      <name>kumi::make_indexes</name>
      <anchorfile>group__kumi__make__indexes.html</anchorfile>
      <anchor>gadba148c334bcf52088dc64992c270fdd</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_make_record</name>
    <title>kumi::make_record</title>
    <filename>group__kumi__make__record.html</filename>
    <member kind="variable">
      <type>constexpr make_record_t</type>
      <name>kumi::make_record</name>
      <anchorfile>group__kumi__make__record.html</anchorfile>
      <anchor>ga931b45076a3ac621c248efa48881b59a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_make_tuple</name>
    <title>kumi::make_tuple</title>
    <filename>group__kumi__make__tuple.html</filename>
    <member kind="variable">
      <type>constexpr make_tuple_t</type>
      <name>kumi::make_tuple</name>
      <anchorfile>group__kumi__make__tuple.html</anchorfile>
      <anchor>ga2a3a7b464afb602d8a722178ac517da8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_map</name>
    <title>kumi::map</title>
    <filename>group__kumi__map.html</filename>
    <member kind="variable">
      <type>constexpr map_t</type>
      <name>kumi::map</name>
      <anchorfile>group__kumi__map.html</anchorfile>
      <anchor>gaeaba737291ba1085d77272eae38a016e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_map_field</name>
    <title>kumi::map_field</title>
    <filename>group__kumi__map__field.html</filename>
    <member kind="variable">
      <type>constexpr map_field_t</type>
      <name>kumi::map_field</name>
      <anchorfile>group__kumi__map__field.html</anchorfile>
      <anchor>gafe68ca583e3e822b20f60ff35e5aa9d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_map_index</name>
    <title>kumi::map_index</title>
    <filename>group__kumi__map__index.html</filename>
    <member kind="variable">
      <type>constexpr map_index_t</type>
      <name>kumi::map_index</name>
      <anchorfile>group__kumi__map__index.html</anchorfile>
      <anchor>ga64a8c36072828fb7b724ba0ab8fc59bc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_map_reduce</name>
    <title>kumi::map_reduce</title>
    <filename>group__kumi__map__reduce.html</filename>
    <member kind="variable">
      <type>constexpr map_reduce_t</type>
      <name>kumi::map_reduce</name>
      <anchorfile>group__kumi__map__reduce.html</anchorfile>
      <anchor>ga396afbfbcefa48f06ad76a34b6f0b523</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_max</name>
    <title>kumi::max</title>
    <filename>group__kumi__max.html</filename>
    <member kind="variable">
      <type>constexpr max_t</type>
      <name>kumi::max</name>
      <anchorfile>group__kumi__max.html</anchorfile>
      <anchor>gab76e53ad197280669806cae2c0cc130c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_max_flat</name>
    <title>kumi::max_flat</title>
    <filename>group__kumi__max__flat.html</filename>
    <member kind="variable">
      <type>constexpr max_flat_t</type>
      <name>kumi::max_flat</name>
      <anchorfile>group__kumi__max__flat.html</anchorfile>
      <anchor>ga718f20d4004a2d3a409bfcfda289ba34</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_member_cast</name>
    <title>kumi::member_cast</title>
    <filename>group__kumi__member__cast.html</filename>
    <member kind="variable">
      <type>constexpr member_cast_t&lt; T &gt;</type>
      <name>kumi::member_cast</name>
      <anchorfile>group__kumi__member__cast.html</anchorfile>
      <anchor>gad2e4009d5d28df5090885b030f08f1f8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_members_of</name>
    <title>kumi::members_of</title>
    <filename>group__kumi__members__of.html</filename>
    <member kind="variable">
      <type>constexpr members_of_t</type>
      <name>kumi::members_of</name>
      <anchorfile>group__kumi__members__of.html</anchorfile>
      <anchor>ga50426580ce9abca59b6a14b398b312ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_min</name>
    <title>kumi::min</title>
    <filename>group__kumi__min.html</filename>
    <member kind="variable">
      <type>constexpr min_t</type>
      <name>kumi::min</name>
      <anchorfile>group__kumi__min.html</anchorfile>
      <anchor>gaafd0c178628f6f756bf0d73a34e75b2f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_min_flat</name>
    <title>kumi::min_flat</title>
    <filename>group__kumi__min__flat.html</filename>
    <member kind="variable">
      <type>constexpr min_flat_t</type>
      <name>kumi::min_flat</name>
      <anchorfile>group__kumi__min__flat.html</anchorfile>
      <anchor>ga31c5b32bd084cb6f18d19706d0f809bb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_none</name>
    <title>kumi::none</title>
    <filename>group__kumi__none.html</filename>
  </compound>
  <compound kind="group">
    <name>kumi_none_of</name>
    <title>kumi::none_of</title>
    <filename>group__kumi__none__of.html</filename>
    <member kind="variable">
      <type>constexpr none_of_t</type>
      <name>kumi::none_of</name>
      <anchorfile>group__kumi__none__of.html</anchorfile>
      <anchor>ga26e030c97733248f67dd2c8fbf527602</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_only</name>
    <title>kumi::only</title>
    <filename>group__kumi__only.html</filename>
    <member kind="variable">
      <type>constexpr kumi::only_t&lt; T &gt;</type>
      <name>kumi::only</name>
      <anchorfile>group__kumi__only.html</anchorfile>
      <anchor>ga26690952147eaa66ecf74378070ee53b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_partition</name>
    <title>kumi::partition</title>
    <filename>group__kumi__partition.html</filename>
    <member kind="variable">
      <type>constexpr partition_t&lt; Pred &gt;</type>
      <name>kumi::partition</name>
      <anchorfile>group__kumi__partition.html</anchorfile>
      <anchor>ga4643116b2dc0dfbd0d15fee408a9c18c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_pop_back</name>
    <title>kumi::pop_back</title>
    <filename>group__kumi__pop__back.html</filename>
    <member kind="variable">
      <type>constexpr pop_back_t</type>
      <name>kumi::pop_back</name>
      <anchorfile>group__kumi__pop__back.html</anchorfile>
      <anchor>ga397f7c5161b7a3ace25c406e83af98fb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_pop_front</name>
    <title>kumi::pop_front</title>
    <filename>group__kumi__pop__front.html</filename>
    <member kind="variable">
      <type>constexpr pop_front_t</type>
      <name>kumi::pop_front</name>
      <anchorfile>group__kumi__pop__front.html</anchorfile>
      <anchor>ga38d1ddeb5090405e79e9b7d898a85133</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_prod</name>
    <title>kumi::prod</title>
    <filename>group__kumi__prod.html</filename>
    <member kind="variable">
      <type>constexpr prod_t</type>
      <name>kumi::prod</name>
      <anchorfile>group__kumi__prod.html</anchorfile>
      <anchor>ga6c139ebafaebc0f7dbca2fd57aee943c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_projection_map</name>
    <title>kumi::projection_map</title>
    <filename>group__kumi__projection__map.html</filename>
    <member kind="function">
      <type></type>
      <name>kumi::projection_map</name>
      <anchorfile>group__kumi__projection__map.html</anchorfile>
      <anchor>ga0ac9f243b64bbbabc2bad542ca03c035</anchor>
      <arglist>(Ts...) -&gt; projection_map&lt; Ts</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_push_back</name>
    <title>kumi::push_back</title>
    <filename>group__kumi__push__back.html</filename>
    <member kind="variable">
      <type>constexpr push_back_t</type>
      <name>kumi::push_back</name>
      <anchorfile>group__kumi__push__back.html</anchorfile>
      <anchor>ga2d60bb8eaba1c8c697b0d4f1e9bf7ce6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_push_front</name>
    <title>kumi::push_front</title>
    <filename>group__kumi__push__front.html</filename>
    <member kind="variable">
      <type>constexpr push_front_t</type>
      <name>kumi::push_front</name>
      <anchorfile>group__kumi__push__front.html</anchorfile>
      <anchor>gad4bd53f162f63af0cbfbd68d8adb5d5c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reduce</name>
    <title>kumi::reduce</title>
    <filename>group__kumi__reduce.html</filename>
    <member kind="variable">
      <type>constexpr reduce_t</type>
      <name>kumi::reduce</name>
      <anchorfile>group__kumi__reduce.html</anchorfile>
      <anchor>gaf7efbfa530d2396e2ed230cc03e4046e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reindex</name>
    <title>kumi::reindex</title>
    <filename>group__kumi__reindex.html</filename>
    <member kind="variable">
      <type>constexpr reindex_t&lt; Projections &gt;</type>
      <name>kumi::reindex</name>
      <anchorfile>group__kumi__reindex.html</anchorfile>
      <anchor>ga3594f15dbfba2f6fda0afc8d1542c449</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_remove</name>
    <title>kumi::remove</title>
    <filename>group__kumi__remove.html</filename>
    <member kind="variable">
      <type>constexpr remove_t</type>
      <name>kumi::remove</name>
      <anchorfile>group__kumi__remove.html</anchorfile>
      <anchor>ga0f52ba0b24ce54052784df91c54ac233</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reorder</name>
    <title>kumi::reorder</title>
    <filename>group__kumi__reorder.html</filename>
    <member kind="variable">
      <type>constexpr reorder_t&lt; I... &gt;</type>
      <name>kumi::reorder</name>
      <anchorfile>group__kumi__reorder.html</anchorfile>
      <anchor>ga32af967d7f453426ccd564d3a0b6c689</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reorder_fields</name>
    <title>kumi::reorder_fields</title>
    <filename>group__kumi__reorder__fields.html</filename>
    <member kind="variable">
      <type>constexpr reorder_fields_t&lt; Name... &gt;</type>
      <name>kumi::reorder_fields</name>
      <anchorfile>group__kumi__reorder__fields.html</anchorfile>
      <anchor>ga8c42552c8f93dad0b83a3903468d02c6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_reverse</name>
    <title>kumi::reverse</title>
    <filename>group__kumi__reverse.html</filename>
    <member kind="variable">
      <type>constexpr reverse_t</type>
      <name>kumi::reverse</name>
      <anchorfile>group__kumi__reverse.html</anchorfile>
      <anchor>ga48f6e5775e61dca804eda8b0bd354d6f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_rotate_left</name>
    <title>kumi::rotate_left</title>
    <filename>group__kumi__rotate__left.html</filename>
    <member kind="variable">
      <type>constexpr rotate_left_t&lt; R &gt;</type>
      <name>kumi::rotate_left</name>
      <anchorfile>group__kumi__rotate__left.html</anchorfile>
      <anchor>gadbc56977f82e2eaefe486c0a9457f01c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_rotate_right</name>
    <title>kumi::rotate_right</title>
    <filename>group__kumi__rotate__right.html</filename>
    <member kind="variable">
      <type>constexpr rotate_right_t&lt; R &gt;</type>
      <name>kumi::rotate_right</name>
      <anchorfile>group__kumi__rotate__right.html</anchorfile>
      <anchor>gaffd5dbb36e1c70d2fc058ffe03afef3e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_split</name>
    <title>kumi::split</title>
    <filename>group__kumi__split.html</filename>
    <member kind="variable">
      <type>constexpr split_t</type>
      <name>kumi::split</name>
      <anchorfile>group__kumi__split.html</anchorfile>
      <anchor>gadb81f4533e81830674c3fc9577d3de93</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_sum</name>
    <title>kumi::sum</title>
    <filename>group__kumi__sum.html</filename>
    <member kind="variable">
      <type>constexpr sum_t</type>
      <name>kumi::sum</name>
      <anchorfile>group__kumi__sum.html</anchorfile>
      <anchor>ga3e8b585399de360c3ab55efc2fa0ed8c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_tie</name>
    <title>kumi::tie</title>
    <filename>group__kumi__tie.html</filename>
    <member kind="variable">
      <type>constexpr tie_t</type>
      <name>kumi::tie</name>
      <anchorfile>group__kumi__tie.html</anchorfile>
      <anchor>ga79c564af50f6eb1c4aa6dac7f08337cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_tiles</name>
    <title>kumi::tiles</title>
    <filename>group__kumi__tiles.html</filename>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, O &gt;</type>
      <name>kumi::tiles</name>
      <anchorfile>group__kumi__tiles.html</anchorfile>
      <anchor>ga3d1b4a8309328d854d7b6234fde3aeb0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_to_array</name>
    <title>kumi::to_array</title>
    <filename>group__kumi__to__array.html</filename>
    <member kind="variable">
      <type>constexpr to_array_t</type>
      <name>kumi::to_array</name>
      <anchorfile>group__kumi__to__array.html</anchorfile>
      <anchor>ga915a6c331bad66be764b814af9f2260f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_to_record</name>
    <title>kumi::to_record</title>
    <filename>group__kumi__to__record.html</filename>
    <member kind="variable">
      <type>constexpr to_record_t</type>
      <name>kumi::to_record</name>
      <anchorfile>group__kumi__to__record.html</anchorfile>
      <anchor>ga163224b58e43457f4cbc65f6817d738f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_to_ref</name>
    <title>kumi::to_ref</title>
    <filename>group__kumi__to__ref.html</filename>
    <member kind="variable">
      <type>constexpr to_ref_t</type>
      <name>kumi::to_ref</name>
      <anchorfile>group__kumi__to__ref.html</anchorfile>
      <anchor>ga271223ada5937ca2e7ea77825b89b144</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_to_tuple</name>
    <title>kumi::to_tuple</title>
    <filename>group__kumi__to__tuple.html</filename>
    <member kind="variable">
      <type>constexpr to_tuple_t</type>
      <name>kumi::to_tuple</name>
      <anchorfile>group__kumi__to__tuple.html</anchorfile>
      <anchor>ga2642659e4d1dfee5339563fe65927385</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_transpose</name>
    <title>kumi::transpose</title>
    <filename>group__kumi__transpose.html</filename>
    <member kind="variable">
      <type>constexpr transpose_t</type>
      <name>kumi::transpose</name>
      <anchorfile>group__kumi__transpose.html</anchorfile>
      <anchor>gaef527bdd76c70e7fded23a9759428f5c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_unique</name>
    <title>kumi::unique</title>
    <filename>group__kumi__unique.html</filename>
    <member kind="variable">
      <type>constexpr unique_t</type>
      <name>kumi::unique</name>
      <anchorfile>group__kumi__unique.html</anchorfile>
      <anchor>ga6479cba59ee95d4a0779e94993ab55a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_values_of</name>
    <title>kumi::values_of</title>
    <filename>group__kumi__values__of.html</filename>
    <member kind="variable">
      <type>constexpr values_of_t</type>
      <name>kumi::values_of</name>
      <anchorfile>group__kumi__values__of.html</anchorfile>
      <anchor>gaa217e07b135cc3295e25689ac4ac2933</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_windows</name>
    <title>kumi::windows</title>
    <filename>group__kumi__windows.html</filename>
    <member kind="variable">
      <type>constexpr tiles_t&lt; N, 1 &gt;</type>
      <name>kumi::windows</name>
      <anchorfile>group__kumi__windows.html</anchorfile>
      <anchor>gade96292292ae11da69415a778ef45ad0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_zip</name>
    <title>kumi::zip</title>
    <filename>group__kumi__zip.html</filename>
    <member kind="variable">
      <type>constexpr zip_t</type>
      <name>kumi::zip</name>
      <anchorfile>group__kumi__zip.html</anchorfile>
      <anchor>ga71c21174289ba175a8d3d4b170cec05f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_zip_max</name>
    <title>kumi::zip_max</title>
    <filename>group__kumi__zip__max.html</filename>
    <member kind="variable">
      <type>constexpr zip_max_t</type>
      <name>kumi::zip_max</name>
      <anchorfile>group__kumi__zip__max.html</anchorfile>
      <anchor>ga0ce4823febfb00cfb197f73332ba7309</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>kumi_zip_min</name>
    <title>kumi::zip_min</title>
    <filename>group__kumi__zip__min.html</filename>
    <member kind="variable">
      <type>constexpr zip_min_t</type>
      <name>kumi::zip_min</name>
      <anchorfile>group__kumi__zip__min.html</anchorfile>
      <anchor>gaf4b9aea3cee7c30fc6a516c632805423</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>kumi_changelog</name>
    <title>Change Log</title>
    <filename>kumi_changelog.html</filename>
    <docanchor file="kumi_changelog.html" title="/__w/kumi/kumi/doc/changelog.md">md__2____w_2kumi_2kumi_2doc_2changelog</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_cpp_vocabulary</name>
    <title>C++ Vocabulary</title>
    <filename>kumi_cpp_vocabulary.html</filename>
    <docanchor file="kumi_cpp_vocabulary.html" title="/__w/kumi/kumi/doc/glossary/cpp_vocabulary.md">md__2____w_2kumi_2kumi_2doc_2glossary_2cpp__vocabulary</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_glossary</name>
    <title>Glossary</title>
    <filename>kumi_glossary.html</filename>
    <subpage>kumi_introduction.html</subpage>
    <subpage>kumi_identity.html</subpage>
    <subpage>kumi_product.html</subpage>
    <subpage>kumi_references.html</subpage>
    <subpage>kumi_cpp_vocabulary.html</subpage>
    <subpage>kumi_nomenclature.html</subpage>
  </compound>
  <compound kind="page">
    <name>kumi_identity</name>
    <title>Identity Elements</title>
    <filename>kumi_identity.html</filename>
    <docanchor file="kumi_identity.html" title="Empty Type">kumi_empty</docanchor>
    <docanchor file="kumi_identity.html" title="Unit Type">kumi_unit</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_introduction</name>
    <title>Type Theoretic Foundations</title>
    <filename>kumi_introduction.html</filename>
    <docanchor file="kumi_introduction.html" title="Origin">origin</docanchor>
    <docanchor file="kumi_introduction.html" title="The Curry-Howard Correspondence">curry_howard</docanchor>
    <docanchor file="kumi_introduction.html" title="Fundamentals">fundamentals</docanchor>
    <docanchor file="kumi_introduction.html" title="Type Cardinality">cardinality</docanchor>
    <docanchor file="kumi_introduction.html" title="Correspondence with KUMI">kumi_correspondence</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_nomenclature</name>
    <title>Nomenclature</title>
    <filename>kumi_nomenclature.html</filename>
    <docanchor file="kumi_nomenclature.html" title="Element">kumi_nomenclature_element</docanchor>
    <docanchor file="kumi_nomenclature.html" title="Member">kumi_nomenclature_member</docanchor>
    <docanchor file="kumi_nomenclature.html" title="Identifier">kumi_nomenclature_identifier</docanchor>
    <docanchor file="kumi_nomenclature.html" title="Field">kumi_nomenclature_field</docanchor>
    <docanchor file="kumi_nomenclature.html" title="Label">kumi_nomenclature_label</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_product</name>
    <title>Product Types</title>
    <filename>kumi_product.html</filename>
    <docanchor file="kumi_product.html" title="Product Constructions">product_construction</docanchor>
    <docanchor file="kumi_product.html" title="Product Type">kumi_product_type</docanchor>
    <docanchor file="kumi_product.html" title="Power Type">kumi_power_type</docanchor>
    <docanchor file="kumi_product.html" title="Record Type">kumi_record_type</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_references</name>
    <title>Bibliography</title>
    <filename>kumi_references.html</filename>
    <docanchor file="kumi_references.html" title="Primary Texts">references_texts</docanchor>
    <docanchor file="kumi_references.html" title="The Curry-Howard Correspondence">references_curry_howard</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_licence</name>
    <title>Licence</title>
    <filename>kumi_licence.html</filename>
    <docanchor file="kumi_licence.html" title="/__w/kumi/kumi/doc/licence.md">md__2____w_2kumi_2kumi_2doc_2licence</docanchor>
  </compound>
  <compound kind="page">
    <name>kumi_reference</name>
    <title>Reference Documentation</title>
    <filename>kumi_reference.html</filename>
  </compound>
  <compound kind="page">
    <name>kumi_setup</name>
    <title>Setup</title>
    <filename>kumi_setup.html</filename>
    <docanchor file="kumi_setup.html" title="Pre-requisites">prerequisites</docanchor>
    <docanchor file="kumi_setup.html" title="Install from the source">setup-source</docanchor>
    <docanchor file="kumi_setup.html" title="Standalone setup">setup-standalone</docanchor>
    <docanchor file="kumi_setup.html" title="As a CMake dependency">dependency</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>The C++20 Compact Tuple Tools</title>
    <filename>index.html</filename>
    <docanchor file="index.html">Examples</docanchor>
  </compound>
</tagfile>
