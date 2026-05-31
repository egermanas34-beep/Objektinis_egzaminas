#include "gtest/gtest.h"
#include "word.h"
#include "wordcounter.h"
#include "urlfinder.h"
TEST(Testai, ConstructorAndGetters)
{
    Word zodis("testas", 3, 1);
    EXPECT_EQ(zodis.getWord(), "testas");
    EXPECT_EQ(zodis.getCount(), 3);
    EXPECT_TRUE(zodis.getSakiniai().count(1) > 0);
}
TEST(Testai, CopyConstructor)
{
    Word zodis1("testas", 3, 1);
    Word zodis2(zodis1);
    EXPECT_EQ(zodis2.getWord(), "testas");
    EXPECT_EQ(zodis2.getCount(), 3);
    EXPECT_TRUE(zodis2.getSakiniai().count(1) > 0);
}
TEST(Testai, MoveConstructor)
{
    Word zodis1("testas", 3, 1);
    Word zodis2(std::move(zodis1));
    EXPECT_EQ(zodis2.getWord(), "testas");
    EXPECT_EQ(zodis2.getCount(), 3);
    EXPECT_TRUE(zodis2.getSakiniai().count(1) > 0);
}
TEST(Testai, CopyAssignment)
{
    Word zodis1("testas", 3, 1);
    Word zodis2;
    zodis2 = zodis1;
    EXPECT_EQ(zodis2.getWord(), "testas");
    EXPECT_EQ(zodis2.getCount(), 3);
    EXPECT_TRUE(zodis2.getSakiniai().count(1) > 0);
}
TEST(Testai, MoveAssignment)
{
    Word zodis1("testas", 3, 1);
    Word zodis2;
    zodis2 = std::move(zodis1);
    EXPECT_EQ(zodis2.getWord(), "testas");
    EXPECT_EQ(zodis2.getCount(), 3);
    EXPECT_TRUE(zodis2.getSakiniai().count(1) > 0);
}
TEST(Testai, ArURL)
{
    UrlFinder uf;
    EXPECT_TRUE(uf.arURL("https://example.com"));
    EXPECT_TRUE(uf.arURL("http://example.com"));
    EXPECT_TRUE(uf.arURL("www.example.com"));
    EXPECT_TRUE(uf.arURL("example.lt"));
    EXPECT_TRUE(uf.arURL("example.com"));
    EXPECT_TRUE(uf.arURL("example.net"));
    EXPECT_TRUE(uf.arURL("example.org"));
    EXPECT_FALSE(uf.arURL("not_a_url"));
}
TEST(Testai, SutvarkytiURL)
{
    UrlFinder uf;
    EXPECT_EQ(uf.sutvarkytiURL("https://example.com."), "https://example.com");
    EXPECT_EQ(uf.sutvarkytiURL("http://example.com,"), "http://example.com");
    EXPECT_EQ(uf.sutvarkytiURL("www.example.com!"), "www.example.com");
    EXPECT_EQ(uf.sutvarkytiURL(".example.lt?"), "example.lt");
    EXPECT_EQ(uf.sutvarkytiURL("example.com;"), "example.com");
    EXPECT_EQ(uf.sutvarkytiURL("example.net:"), "example.net");
    EXPECT_EQ(uf.sutvarkytiURL("example.org-"), "example.org");
}
